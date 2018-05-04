// file-parsing API for JOS 
// --- Jacob Mealey --- 
#include "file_parse.h"

char line_buffer[20][20];
int line = 0;

void toFileBuff(char character, char file_buffer[20][20][20])
{
	addToBuff(line_buffer, character);
	if(character == '\n'){
		pushTofile(file_buffer, line_buffer);
		clearBuff(line_buffer);
	}
}

void printFile(char file_buffer[20][20][20])
{
	for (int i = 0; i < 15; i++){
		printTextBuff(file_buffer[i]);
	}
}

void pushTofile(char file[20][20][20], char buffer[20][20])
{
	for(int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			file[line][i][j] = buffer[i][j];
		}
	}
}



