//common.c for all common tasks 
//Jacob Mealey
//
#include "common.h"

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
void removec(char* a, char*b)
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
