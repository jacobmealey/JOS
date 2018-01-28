#include "shell.h"
char *command_buffer = "\0";

void sh_write(char data)
{
	putchar(data, 0x0F);
	if(data == '\n')
	{
		int i = 0;
		while(command_buffer[i] != '\0')
		{
			putchar(command_buffer[i], 0x0F);
			i++;
		}
		command_buffer = command_buffer - string_length(command_buffer);
	}
	else
	{
		concatc(command_buffer, data, command_buffer);
	}
}
