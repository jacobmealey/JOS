// ata.c
// ata driver for JOS
// most code pulled from former project PortOS [https://github.com/MatthewGallant/PortOS]
// Author: Jacob Mealey

#include "ata.h"


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
	for(int i = 0; i < sectors; i++)
		readSector(disk,address+i,sect+i*512);
}

int getFirstPartition(int disk){
	prepareDisk(disk,0);
	uint16_t pos = 0;
	for(int i = 0; i < 256; i++){
		uint16_t tmpword = inw(0x1F0);
		if(i == 227)
			pos = tmpword;
	}
	return pos;
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
