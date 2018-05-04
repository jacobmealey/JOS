// file-parsing API for JOS 
// --- Jacob Mealey --- 
#include "common.h"
#include "fat.h"
#include "vga.h"
#include "parse.h"

void toFileBuff(char character, char file_buffer[20][20][20]);
void printFile(char file_buffer[20][20][20]);
void pushTofile(char file[20][20][20], char buffer[20][20]);
