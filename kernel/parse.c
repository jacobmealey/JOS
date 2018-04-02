// Text parsing for JOS 
// --- Jacob Mealey --- 

#include "parse.h"

char * text_buffer;

void add_buff(char character)
{
	concatChar(text_buffer, character, text_buffer);
}
