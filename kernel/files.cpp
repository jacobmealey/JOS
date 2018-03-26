// Files.c 
// File handling API for JOS
// Author: Jacob Mealey

extern "C"{
  #include "files.h"
  #include "common.h"

  int makefile(char* file_name){
    files file;
    return file.makeFile(file_name);
  }
}



int files::makeFile(char* file_name)
{
	printf("Making file: ", normal);
	printf(file_name, normal);
    printf("\n", normal);
	printf("(Not really ATM)\n", normal);
	return 1;
}
