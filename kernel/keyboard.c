#include "keyboard.h"
uint8_t inb(uint16_t port)
{
	uint8_t ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}
char getScancode()
{
	char flag = inb(0x64);
	while(!(flag & 1)) {
		flag = inb(0x64);
	}
	return inb(0x60);
}
