// Text parsing for JOS 
// testing code
// --- Jacob Mealey --- 

#include "parse.h"

char *text_buffer;
char buff_array[20][20]; // This shouldn't work but does. LOL
int buff_array_len = 0;

void addToBuff(char character)
{
	if(character == ' '){
		pushToArray(text_buffer);
		clearBuff();
	} else if (character == '\n'){
		printTextBuff();
		clearLineBuff();
	} else {
		if(character== '\b'){
			removeChar(text_buffer, text_buffer);
			return;
		}
		concatChar(text_buffer, character, text_buffer);
	}
}

void pushToArray(char* buffer)
{
	printf("pushing to array\n", red);
	for (int i = 0; i < 20; i++)
		buff_array[buff_array_len][i] = buffer[i];
	buff_array_len++;
}
void printTextBuff()
{
	for(int i = 0; i < 20; i++)
		printf(buff_array[i], normal);
}

void clearBuff()
{
	for(int i = 0; i <= 100 ; i++)
		removeChar(text_buffer, text_buffer);
}

void clearLineBuff()
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 50; j++)
			removeChar(buff_array[i], buff_array[i]);
	}
}
