#ifndef FAT_H
#define FAT_H

#include "common.h"

typedef struct fat32part{

	uint8_t disk;
	uint16_t part_sect;
	uint8_t sectors_per_cluster;
	uint32_t root_dir_sect;
	uint32_t root_dir_clust;
	uint32_t cluster_begin_sect;
	uint8_t num_fats;
	uint32_t sectors_per_fat;
	uint16_t reserved_sectors;
	uint32_t fat_sect;
	uint32_t current_dir_clust;
} fat32part;

int isPartitionFAT32(int disk, int sect);
void listFiles(int disk, int addr, int len);
void listAllFiles(int disk);
#endif
