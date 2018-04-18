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

char *text_buffer;

void addToBuff(char buff[20][20], char character);
void pushToArray(char buff[20][20], char* buffer);
void printTextBuff(char buff[20][20]);
void clearBuff(char buff[20][20]);
void clearLineBuff(char buff[20][20]);
