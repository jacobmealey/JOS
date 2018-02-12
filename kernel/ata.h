// ata.h
// ata driver for JOS
// most code pulled from former project PortOS (https://github.com/MatthewGallant/PortOS)
// Author: Jacob Mealey

#ifndef ATA_H
#define ATA_H

void readSector(int disk, int address, uint8_t *sect);
void prepareDisk(int disk, int address);
void readSectors(int disk, int address, int sectors, uint8_t *sect);
int getFirstPartition(int disk);
int isPartitionFAT32(int disk, int sect);
void listFiles(int disk, int addr, int len);
void listAllFiles(int disk);
int getRoot(int disk);
int getRootEntries(int disk);

#endif
