#include "shell.h"
char *command_buffer = "\0";

void clear_buffer()
{
		command_buffer = command_buffer - string_length(command_buffer);
}
void sh_init()
{
	printf("JOS v0.0.1\n", normal);
	putchar('>', normal);
}
int commands_check(char * command)
{
	if(string_compare(command, "clear")){
		clear_screen(normal);
		return 1;
	}
	if(string_compare(command, "mkfile")){
		if(isPartitionFAT32(0 , 0) != 1 ){
			printf("No fat32 formatted disk!\nplease insert disk on port 0", red);
		}
		return 1;
	}
	if(string_compare(command, "list")){
		listAllFiles(0);
		return 1;
	}
	return 0;
}
void sh_write(char data)
{
	putchar(data, normal);
	if(data == '\n' )
	{
		commands_check(command_buffer);
		clear_buffer();
		putchar('\n', normal);
		putchar('>', normal);
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


