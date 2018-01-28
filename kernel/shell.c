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
		return;
	}
	else
	{
		concatc(command_buffer, data, command_buffer);
	}
}
