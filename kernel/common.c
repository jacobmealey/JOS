// common.c for all common tasks 
// Author: Jacob Mealey
//
// note some functions and blocks of code are from PortOS [https://github.com/MatthewGallant/PortOS] 
// and from CodeOS [https://github.com/Codepixl/CodeOS]

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

//outbfor getting data in between I/O ports
//imperative for VGA driver! 
void outb(uint16_t port, uint8_t value)
{
	    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

int stringLength(char* string)
{
	int i = 0;
	// '\0' represents the end of a string
	while(string[i] != '\0')	
	{
		i++;
	}
	return i;
}

void concatChar(char* a, char b, char* c)
{
	int len = stringLength(a) + 1;
	int i =0;
	while(i < stringLength(a))
	{
		c[i] = a[i];
		i++;
	}
	c[i] = b;
	c[len] = '\0';
}

void removeChar(char* a, char*b)
{
	int len = stringLength(a);
	int i;
	for(i = 0; i < len-1; i++){
		b[i] = a[i];
	}
	b[i] =  '\0';
}

// --> Can this be made more efficiant? 
int stringCompare(char* str1, char* str2)
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

// This will pause until there is input from a PS/2 device
void pause()
{
	while(inb(0x60) & 0x80);

}

// All of the functions below were to make the PortOS/CodeOS 
// Drivers work
void println(char * string)
{
	printf(string, normal);
	printf("\n", normal);
}

int indexOf(char c, char * string)
{
	int i = 0;
	while(string[i] != '\0'){
		if(string[i] == c)
			return i;
		i++;
	}
	return stringLength(string);
}

int indexOfn(char c, int n, char * string)
{
	int i = 0;
	int count = 0;
	while(string[i] != '\0'){
		if(string[i] == c){
			if(count == n){
				return i;
			}
			else{
				count++;
			}
		}
		i++;
	}
	return stringLength(string);
}

void substr(int i, char * src, char * dest)
{
	memcpy(dest, src, i);
	dest[i] = '\0';
}

void substrr(int s, int e, char* source, char* destination)
{
	memcpy(destination, &source[s], e-s);
	destination[e-s] = '\0';
}


void strcpy(char* string_one, char* string_two)
{
	int i = 0;
	while(string_one[i] != '\0')
		string_two[i] = string_one[i];
}

void * memcpy(void * dest, const void * src, size_t count)
{
	const char *sp  = (const char*) src;
	char *dp = (char *) dest;
	for(; count != 0; count--)
		*dp++ = *sp++;
	return dest;
}

int strcmp(char* str1, char* str2)
{
	int i = 0;
	int flag = 1;

	for(;str1[i] != '\0' && str2[i] != '\0'; i++){
		if(str1[i] != str2[i]){
			flag = 0;
			return flag;
		}
	}
	return flag;
}

int contains(char * string, char* contained)
{
	int i = 0;
	int contlen = stringLength(contained);
	int flag_a = 0;
	int flag_b = 0;
	while(string[i+contlen-1] != '\0'){
		flag_b = 1;
		for(int j = 0; j < stringLength(contained); j++){
			if(contained[j] != string[i + j])
				flag_b = 0;
		}
		if(flag_b){
			flag_a = 1;
		}
		i++;
	}
	return flag_a;
}

int countOf(char c, char *str)
{
	 //Returns number of instances of c in str
	 int count = 0;
	 for(int i = 0; i < stringLength(str); i++){
	 	if(str[i] == c)
			count++;
	 }
	 return count;
}
