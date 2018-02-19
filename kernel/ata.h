// ata.h
// ata driver for JOS
// most code pulled from former project PortOS (https://github.com/MatthewGallant/PortOS)
// Author: Jacob Mealey

#ifndef ATA_H
#define ATA_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdbool.h> /* C doesn't have booleans by default. */

#include <stddef.h>
#include <stdint.h>

#include "common.h"


void readSector(int disk, int address, uint8_t *sect);
void prepareDisk(int disk, int address);
void readSectors(int disk, int address, int sectors, uint8_t *sect);
int getFirstPartition(int disk);
int getRoot(int disk);
int getRootEntries(int disk);

#endif
