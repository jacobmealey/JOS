// Files.h
// File handling API for JOS
// Author: Jacob Mealey

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

int makeFile(const char* file_name);

#endif
