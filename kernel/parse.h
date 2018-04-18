#ifndef PARSE_C
#define PARSE_C
// text parser for JOS 
// --- Jacob Mealey --- 

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdbool.h> /* C doesn't have booleans by default. */

#include <stddef.h>
#include <stdint.h>

#include "vga.h"
#include "common.h"


typedef struct parse 
{
	char *text_buffer;
	char buff_array[20][20];
} Parse;

void addToBuff(Parse buff, char character);
void pushToArray(char buff[20][20], char* buffer);
void printTextBuff(Parse buff);
void clearBuff(Parse buff);
void clearLineBuff(Parse buff);
#endif
