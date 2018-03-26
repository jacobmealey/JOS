// Files.h
// File handling API for JOS
// Author: Jacob Mealey
//
// When using C++ in C you can't actually include the header
// you just use implicit declerations

#ifndef FILES_H
#define FILES_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif


#include <stddef.h>
#include <stdbool.h> /* C doesn't have booleans by default. */

#include <stddef.h>
#include <stdint.h>


#include "common.h"
#include "fat.h"
#include "vga.h"

class files {
  public:
    int makeFile(char* file_name);
};

#endif
