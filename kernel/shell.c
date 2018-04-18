// shell.c
// dumb shell for JOS
// Author: Jacob Mealey

#include "shell.h"

char command_buffer[20][20];

void shInit()
{
	printf("JOS v0.0.1\n", normal);
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
	}
	if(stringCompare(command[0], "list")){
		if(exists(currentFile))
			printf("File Does Exist",normal);
		println("");
		printFileContents(currentFile);
		println("");
	}
}

void shWrite(char data)
{
	addToBuff(command_buffer, data);
	putchar(data, normal);
	if(data == '\n' )
	{
		commandCheck(command_buffer);
		clearBuff(command_buffer);
		putchar('>', normal);
	}
}


