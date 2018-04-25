// Text parsing for JOS 
// testing code
// --- Jacob Mealey --- 

#include "parse.h"

int buff_array_pos = 0;
char * text_buffer;

void addToBuff(char buff[20][20], char character)
{
	if(character== '\b'){
		removeChar(text_buffer, text_buffer);
		return;
	}
	else if(character == ' '){
		pushToArray(buff, text_buffer);
		clearBuff(buff);
	} else if (character == '\n'){
		pushToArray(buff, text_buffer);
		clearBuff(buff);
		buff_array_pos = 0;
	} else {
		concatChar(text_buffer, character, text_buffer);
	}
}

void pushToArray(char buff[20][20], char* buffer)
{
	for (int i = 0; i < 20; ++i) 
		buff[buff_array_pos][i] = buffer[i];
	buff_array_pos++;
}
void printTextBuff(char buff[20][20])
{
	println("");
	for(int i = 0; i < 20; i++){
		printInt(i, normal);
		printf(". ", normal);
		printf(buff[i], normal);
		printf("\n", normal);
	}
}

void clearBuff()
{
	for(int i = 0; i <= 100 ; i++)
		removeChar(text_buffer, text_buffer);
}

void clearLineBuff(char buff[20][20])
{
	clearBuff(buff);
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 50; j++)
			removeChar(buff[i], buff[i]);
	}
}
