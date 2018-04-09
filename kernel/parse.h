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

char * text_buffer;

void addToBuff(char character);
void pushToArray(char* buffer);
void printTextBuff();
void clearBuff();
void clearLineBuff();
