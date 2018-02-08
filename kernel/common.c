//common.c for all common tasks 
//Jacob Mealey
//
//note some functions and blocks of code are from PortOS a former project of mine
#include "common.h"


//inb for getting data in between I/O ports
//imperative for keyboard! 
uint8_t inb(uint16_t port)
{
	uint8_t ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

uint16_t inw(uint16_t port)
{
	uint16_t ret;
	asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

//inb for getting data in between I/O ports
//imperative for VGA driver! 
void outb(uint16_t port, uint8_t value)
{
	    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

int string_length(char* string)
{
	int i = 0;
	while(string[i] != '\0')	
	{
		i++;
	}
	return i;
}

void concatc(char* a, char b, char* c)
{
	int len = string_length(a) + 1;
	int i =0;
	while(i < string_length(a))
	{
		c[i] = a[i];
		i++;
	}
	c[i] = b;
	c[len] = '\0';
}

void removechar(char* a, char*b)
{
	int len = string_length(a);
	int i;
	for(i = 0; i < len-1; i++){
		b[i] = a[i];
	}
	b[i] =  '\0';
}

int string_compare(char* str1, char* str2)
{
	int i = 0;
	int flag = 0;
	
	while(str1[i]!='\0' && str2[i]!='\0')	
	{
		if(str1[i] != str2[i]){
			flag = 1;
			break;
		}
		i++;
	}
	if(flag == 0 && str1[i]=='\0' && str2[i]=='\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void pause()
{
	while(inb(0x60) & 0x80){

	}
}
