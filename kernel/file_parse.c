// file-parsing API for JOS 
// Authour: Jacob Mealey
#include "file_parse.h"

char file_buffer[20][20];

void toFileBuff(char character)
{
	addToBuff(file_buffer, character);
}

void printFile()
{
	printTextBuff(file_buffer);
}


