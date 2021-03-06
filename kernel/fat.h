// FAT filesystem implementation
// for JOS original code from
// CodeOS
// --- Jacob Mealey ---#ifndef FAT32_H
#ifndef FAT32_H
#define FAT32_H

#include "heap.h"
#include "common.h"
#include "ata.h"
#include "file_parse.h"

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
	uint8_t is_fat;
} fat32part;

typedef struct fat32file{
	uint32_t cluster;
	uint32_t size;
	uint32_t dir_cluster;
	uint8_t attrib;
	char* name; 
} fat32file;

fat32part currentfat32part;
fat32file currentFile;

void setupDisk();
void isPartitionFAT32(int disk, int sect);
fat32part getFat32Part(int disk, int part_sect);
uint32_t clusterToLBA(uint32_t cluster);
uint32_t clusterToLBAOther(fat32part p, uint32_t cluster);
void setCurrentFat32part(fat32part p);
void listDir(uint32_t cluster, char *filter);
void listCurrentDir(char *filter);
uint8_t changeDir(char *dir);
uint8_t changeOneDir(char *dir);
int isDirectory(fat32file file);
fat32file getFile(char *file);
int exists(fat32file file);
uint32_t getClusterOfEntry(uint8_t *entry);
uint32_t getClusterChainSize(uint32_t cluster);
uint32_t getFATSectorForCluster(uint32_t cluster);
uint32_t getNextCluster(uint32_t cluster);
uint32_t getClusterOfFile(char *file);
void loadFile(fat32file file, char buff[20][20][20]);
void printCurrentDir();
fat32part getCurrentFat32Part();
void fatInfo();

#endif
