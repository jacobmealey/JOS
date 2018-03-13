// shell.c
// dumb shell for JOS
// Author: Jacob Mealey

#include "shell.h"

char *command_buffer = "\0";

void clearBuffer()
{
		command_buffer = command_buffer - stringLength(command_buffer);
}

void shInit()
{
	printf("JOS v0.0.1\n", normal);
}

void prompt()
{
	putchar('>', normal);
}



void commandCheck(char * command)
{
	if(stringCompare(command, "clear")){
		clear_screen(normal);
	}
	if(stringCompare(command, "mkfile")){
		printf("Coming soon to an OS near you :)", light_purple);
	}
	if(stringCompare(command, "list")){
		if(exists(currentFile)){
			printf("File Does Exist",normal);
		}
		println("");
		printFileContents(currentFile);
		println("");
	}
}

void shWrite(char data)
{
	putchar(data, normal);
	if(data == '\n' )
	{
		commandCheck(command_buffer);
		clearBuffer();
		putchar('>', normal);
	}
	else
	{
		if(data == '\b'){
			removeChar(command_buffer, command_buffer);
			return;
		}

		concatChar(command_buffer, data, command_buffer);
	}
}


