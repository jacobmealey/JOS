// Text parsing for JOS 
// testing code
// --- Jacob Mealey --- 

#include "parse.h"

char * text_buffer;
char * buff_array[25]; // This shouldn't work but does. LOL
int buff_array_len = 0;

void addToBuff(char character)
{
	if(character == '\n'){
		pushToArray(text_buffer);
		printf(text_buffer, red);
		clearbBuff();
	} else {
		concatChar(text_buffer, character, text_buffer);
	}
}

void pushToArray(char* buffer)
{
	printf("pushing to array\n", red);
	buff_array[buff_array_len] = buffer;
	buff_array_len++;
}

void printTextBuff()
{
	for(int i = 0; i <= 25; i++)
		printf(buff_array[i], normal);
}

void clearbBuff()
{
	for(int i = 0; i <= stringLength(text_buffer); i++)
		removeChar(text_buffer, text_buffer);
}
