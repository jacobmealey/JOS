// keyboard.c 
// keyboard / ps2 driver for JOS
// Author: Jacob Mealey

#include "keyboard.h"
#include "vga.h"
#include "shell.h"
#include "common.h"

static char keyboard_bus[256] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,
	0, 27, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+',
	'\b', '\t',
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
	0,
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',
	'\"', '~', 0, '|',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	'<', '>', '?', 0, '*',
	0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0
	
};

char getScancode()
{
	char flag = inb(0x64);
	while(!(flag & 1)) {
		flag = inb(0x64);
	}
	return inb(0x60);
}
void handleKeys()
{
	unsigned char key = getScancode();
		
	// NOTE: Maybe try using a while loop for this 
	// in order to do more then one key while shifted
	if (key == 0x2A){			
		while(1){
			unsigned char key_shift = getScancode();
			// If shift is released
			if(key_shift == 0xAA)
				return;
			// if any key is released do nothing
			else if (key_shift >= 0x81)
				;
			else
				shWrite(keyboard_bus[key_shift + 90]);
		}
	}
	else if(key < 54){
		// Pushing to shell so the characters can be 
		// handled by a more complex system then the VGA driver
	       	shWrite(keyboard_bus[key]);
	}
}
