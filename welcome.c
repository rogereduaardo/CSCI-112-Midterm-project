// welcome.c
// The IMPLEMENTATION

// System Header Files
#include <stdio.h>

// Project Header Files
#include "welcome.h"

#define PROG_NAME "Guess What"
#define VERSION "Version 3.0.0"
#define DEVELOPER "Roger Martinez"

void welcome()
{
  printf("\n%s\n\n%s\n\nCopyright(c) 2023\n\n%s\n", PROG_NAME, VERSION, DEVELOPER);
}
