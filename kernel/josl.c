// JOSL 
// Jacob Operating system Scripting Language
// ---- Jacob Mealey ----

#include "josl.h"

char josl_buff[20][20][20];

void josl(fat32file file)
{
	loadFile(file, josl_buff);
	if(stringCompare(josl_buff[0][0], "Hello,")){
		printf("Goodbye", normal);
	} else {
		printf("Sorry", normal);
	}
}

