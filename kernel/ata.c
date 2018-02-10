#include "common.h"
#include "ata.h"

// ata driver for JOS
// most code pulled from former project PortOS (https://github.com/MatthewGallant/PortOS)
uint8_t boot_disk = 0;
uint8_t ata_buf[512];
uint8_t ata_buf2[512];
uint8_t *buf = ata_buf, *buf2 = ata_buf2;
const char *fat32sig = "FAT32   ";

void prepareDisk(int disk, int address){
	outb(0x1F1,0x00);
	outb(0x1F2,0x01);
	outb(0x1F3,(uint8_t)address);
	outb(0x1F4,(uint8_t)(address >> 8));
	outb(0x1F5,(uint8_t)(address >> 16));
	outb(0x1F6,0xE0 | (disk << 4) | ((address >> 24) & 0x0F));
	outb(0x1F7,0x20);
	while (!(inb(0x1F7) & 0x08)) {}
}

void readSector(int disk, int address, uint8_t *sect){
	prepareDisk(disk, address);
	for(int i = 0; i < 256; i++){
		uint16_t tmp = inw(0x1F0);
		sect[i*2] = (uint8_t)tmp;
		sect[i*2+1] = (uint8_t)(tmp >> 8);
	}
}

void readSectors(int disk, int address, int sectors, uint8_t *sect){
	for(int i = 0; i < sectors; i++){
		readSector(disk,address+i,sect+i*512);
	}
}

int getFirstPartition(int disk){
	prepareDisk(disk,0);
	uint16_t pos = 0;
	for(int i = 0; i < 256; i++){
		uint16_t tmpword = inw(0x1F0);
		if(i == 227){
			pos = tmpword;
		}
	}
	return pos;
}

int isPartitionFAT32(int disk, int sect){
	readSector(disk, sect, buf);
	for(int i = 0; i < 8; i++){
		if(buf[0x52+i] != fat32sig[i])
			return 0; 
	}
	return 1;
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
				putchar('\n', normal);
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
	for (int i = 0; i < 1000; i++)
		listFiles(disk, i, 100);
}
int getRoot(int disk)
{
	int position = getFirstPartition(disk);
	prepareDisk(0, position);
	int rsects = 0;
	int fats = 0;
	int size = 0;

	for (int i = 0; i < 255; i++){
		uint16_t tmpword = (uint16_t)inw(0x1F0);
		if(i == 0x7){
			rsects = (uint16_t)(tmpword);
		}
		if(i == 0x8){
			fats = (uint16_t)(tmpword);
		}
		if(i == 0xb){
			size = tmpword;
		}
	}
	return fats*size+rsects+position;
}
int getRootEntries(int disk)
{
	prepareDisk(disk, getFirstPartition(disk));
	uint16_t a = 0;
	uint16_t b = 0;
	for(int i = 0; i <255; i++){
		uint16_t tmp = (uint16_t)inw(0x1F0);
		if(i == 0x8)
			a = tmp >> 8;
		if(i == 0x9)
			b = tmp << 8;
	}
	printInt(a, normal);
	printf("\n", normal);
	return a + b;
}
