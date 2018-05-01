// file-parsing API for JOS 
// Authour: Jacob Mealey
#include "file_parse.h"

char line_buffer[20][20];
char file_buffer[100][20][20];
int line = 0;

void toFileBuff(char character)
{
	addToBuff(line_buffer, character);
	if(character == '\n'){
		line++;
		clearLineBuff(line_buffer);
	}
}

void printFile()
{
	for (int i = 0; i < 100; i++){
		printTextBuff(file_buffer[i]);
	}
}

void pushTofile(char * file[20][20], char buffer[20][20])
{
	for(int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			file[line][i][j] = buffer[i][j];
		}
	}
}



