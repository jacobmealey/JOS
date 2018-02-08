#include "shell.h"
char *command_buffer = "\0";

void sh_init()
{
	printf("JOS v0.0.1\n", 0x0F);
	putchar('>', 0x0F);
}
void commands_check(char * command)
{
	if(string_compare(command, "clear")){
		clear_screen(0x0F);
	}
	if(string_compare(command, "mkfile")){
		if(isPartitionFAT32(0 , 0) != 1 ){
			printf("No fat32 formatted disk!\nplease insert disk on port 0", 0x04);
		}
	}
	if(string_compare(command, "list")){
		printInt(getRoot(0), normal);
		printf("\n", normal);
		printInt(getRootEntries(0), normal);
		printf("\n", normal);
		for(int i = 0; i < 2000; i++){
			listFiles(0, i, 200); 
		}
	}
}
void sh_write(char data)
{
	putchar(data, 0x0F);
	if(data == '\n')
	{
		printf(command_buffer, 0x0F);
		printf("\n", 0x0F);
		commands_check(command_buffer);
		command_buffer = command_buffer - string_length(command_buffer);
		putchar('\n', 0x0F);
		putchar('>', 0x0F);
	}
	else
	{
		if(data == '\b'){
			removechar(command_buffer, command_buffer);
			return;
		}

		concatc(command_buffer, data, command_buffer);
	}
}


