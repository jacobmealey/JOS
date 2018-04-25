// shell.c
// dumb shell for JOS
// Author: Jacob Mealey

#include "shell.h"

char command_buffer[20][20];

void shInit()
{
	printf("JOS v0.0.1\n", normal);
	clearLineBuff(command_buffer);
}

void prompt()
{
	putchar('>', normal);
}


void commandCheck(char command[20][20])
{
	if(stringCompare(command[0], "clear"))
		clear_screen(normal);
	if(stringCompare(command[0], "mkfile")){
		//makeFile("file.txt\n");
	        makefile("file");
		printf(command[1], normal);
	}
	if(stringCompare(command[0], "list")){
		if(exists(currentFile))
			printf("File Does Exist",normal);
		println("");
		printFileContents(currentFile);
		println("");
	}
	if(stringCompare(command[0], "fatinfo")){
		fatInfo();
	}
	if(stringCompare(command[0], "shutdown")){
		powerdown();
	}
}

void shWrite(char data)
{
	addToBuff(command_buffer, data);
	putchar(data, normal);
	if(data == '\n' )
	{
		commandCheck(command_buffer);
		clearLineBuff(command_buffer);
		prompt();
	}
}


