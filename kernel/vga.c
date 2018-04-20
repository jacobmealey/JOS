// vga.c
// VGA driver for JOS
// Author: Jacob Mealey
//
// modified code from PortOS

// Includes
#include "vga.h"

uint8_t cursor_x = 0;
uint8_t cursor_y = 0;
char *vidmem = (char *)0xb8000;


void clear_screen(uint8_t color)
{
   int i;
   for(i = 0; i < 80*25*2; i++){
	   vidmem[i++] = ' ';
	   vidmem[i] = color;
   }
   cursor_x = 0;
   cursor_y = 0;
   move_cursor();
}

void move_cursor()
{
   uint16_t cursorLocation = cursor_y * 80 + cursor_x;
   outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
   outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
   outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
   outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

void putchar(char c, uint8_t color)
{
	uint16_t location;
	if(c == 0x08 && cursor_x){
		cursor_x--;
		location = (cursor_y * 80 + cursor_x)*2;
		vidmem[location] = ' ';
		vidmem[location+1] = 0x0F;
	}else if(c == 0x09)
		cursor_x = (cursor_x+8) & ~(8-1);
	else if(c == '\n'){
		cursor_x = 0;
		cursor_y++;
	}else if(c == '\b')
		cursor_x--;
	else if(c >= ' '){
		location = (cursor_y * 80 + cursor_x)*2;
		vidmem[location] = c;
		vidmem[location + 1] = color;
		cursor_x++;
	}
	
	if(cursor_x >= 80){
		cursor_x = 0;
		cursor_y++;
	}
	scroll(color);
	move_cursor();
}

void printf(char *c, uint8_t color)
{
	int i = 0;
	while(c[i])
		putchar(c[i++], color);
}

void printInt(int n, uint8_t color)
{
	if(n == 0){
		printf("0",color);
		return;
	}
	char buffer[50];
	int i = 0;

	int isNeg = n<0;

	unsigned int n1 = isNeg ? -n : n;

	while(n1!=0)
	{
		buffer[i++] = n1%10+'0';
		n1=n1/10;
	}

	if(isNeg)
		buffer[i++] = '-';

	buffer[i] = '\0';

	for(int t = 0; t < i/2; t++)
	{
		buffer[t] ^= buffer[i-t-1];
		buffer[i-t-1] ^= buffer[t];
		buffer[t] ^= buffer[i-t-1];
	}
	
	printf(buffer, color);
}

void scroll(uint8_t color)
{
   if(cursor_y >= 25){
       	int i = 80*2;
		while(i < 80*25*2){
			vidmem[i-(80*2)] = vidmem[i];
			i++;
		}
		i = 80*2*24;
		while(i < 80*25*2){
			vidmem[i++] = ' ';
			vidmem[i++] = 0x07;
		}
		cursor_y--;
   }
}


int getY()
{
	return cursor_y;
}

int getX()
{
	return cursor_x;
}

int getPos()
{
	return ((cursor_y*80)+cursor_x)*2;
}

void setPos(int x, int y)
{
	cursor_x = x;
	cursor_y = y;
	move_cursor();
}
