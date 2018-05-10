// shell.c
// dumb shell for JOS
// --- Jacob Mealey --- 

#include "shell.h"

char command_buffer[20][20];
char file_buff[20][20][20];

void shInit()
{
	centerPrint("     ___  _______  _______ ", normal);
    	centerPrint("    |   ||       ||       |", normal);
   	centerPrint("    |   ||   _   ||  _____|", normal);
	centerPrint("    |   ||  | |  || |_____ ", normal);
	centerPrint(" ___|   ||  |_|  ||_____  |", normal);
	centerPrint("|       ||       | _____| |", normal);
	centerPrint("|_______||_______||_______|", normal);
	centerPrint("Press Any Key", normal);
	pause();
	clearLineBuff(command_buffer);
}

void prompt()
{
	putchar('>', normal);
}


void commandCheck(char command[20][20])
{
	if(stringCompare(command[0], "clear")){
		clear_screen(normal);
	}else if(stringCompare(command[0], "mkfile")){
		//makeFile("file.txt\n");
		printf(command[1], normal);
	}else if(stringCompare(command[0], "list")){
		println("Contents: ");
		currentFile = getFile(command[1]);
		loadFile(currentFile, file_buff);
		printFile(file_buff);
		println("");
	}else if(stringCompare(command[0], "fatinfo")){
		fatInfo();
	}else if(stringCompare(command[0], "shutdown")){
		powerdown();
	}else if(stringCompare(command[0], "josl")){
		currentFile = getFile(command[1]);
		josl(currentFile);
	} else{
		printf("Unknown Command: ", normal);
		printf(command[0], red);
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
		clearLineBuff(command_buffer);
		prompt();
	}
}


