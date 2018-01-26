#include "shell.h"
void sh_write(char data)
{
	putchar(data, 0x0F);
}
