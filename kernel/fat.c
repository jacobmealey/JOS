#include "fat.h"
#include "ata.h"
#include "common.h"

fat32part current_fat32;
uint8_t boot_disk = 0;
uint8_t *buf = ata_buf, *buf2 = ata_buf2;
const char *fat32_sig = "FAT32   ";

void setupDisk()
{
	isPartitionFAT32(0, 0);

}

int getFirstPart(int disk)
{
	prepareDisk(disk, 0);
	uint16_t pos = 0;
	for(int i = 0; i <= 255; i++){
		uint16_t tmpword = (uint16_t)inw(0x1F0);
		if(i == 227){
			pos = tmpword;
		}
	}
	return pos;
}

int getRoot(int disk)
{
	int pos = getFirstPart(disk);
	prepareDisk(0, pos);
	int reserved_sectors = 0;
	int fats = 0;
	int size = 0;

	for(int i = 0; i < 255; i++){
		uint16_t tmpword = (uint16_t)inw(0x1F0);
		if(i == 0x7)
			reserved_sectors = (char)(tmpword);
		if(i == 0x8)
			fats = (char)(tmpword);
		if(i == 0xb)
			size = tmpword;
	}
	return fats*size+reserved_sectors+pos;
}

void isPartitionFAT32(int disk, int sect){
	readSector(disk, sect, buf);
	for(int i = 0; i < 8; i++){
		if(buf[0x52+i] != fat32_sig[i])
			current_fat32.is_fat = 0;
	}
	current_fat32.is_fat = 1;
}

void listFiles(int disk, int addr, int len){
	int listed = 0;
	for(int s = 0; s < len; s++){

		prepareDisk(disk,addr+s);

	  	unsigned char sect[512];

		for(int i = 0; i < 255; i++){
			uint16_t tmpword = (uint16_t)inw(0x1F0);
			sect[i*2] = ((unsigned char)(tmpword));
			sect[i*2+1] = ((unsigned char)(tmpword >> 8));
		}
		for(int i = 0; i < 512; i+=32){
			if(sect[i+11] != 0x0f && sect[i] != 0xe5 && sect[i+11] != 0x08 && sect[i] != 0){
				if(listed == 23){
					printf("Press any key to continue...\n", normal);
					pause();
					listed = 0;
				}
				listed++;
				for(int j = 0; j < 11; j++){
					if(sect[i+j] != 0x20)
						putchar(sect[i+j], normal);
					if(j == 7 && (sect[i+11] >> 4) != 0x1)
						putchar('.', normal);
				}
				if((sect[i+11] >> 4) == 0x1){
					printf(" <DIR>", normal);
				}
				printf(" ", normal);
			}
		}
	}
}

void listAllFiles(int disk){
	/*
	for (int i = 8; i < 32; i++){
		printInt(i, red);
		listFiles(disk, i, 3021);
	}
	*/
	listFiles(disk, 18, 3021);

}
