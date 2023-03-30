// help.c
// The IMPLEMENTATION

#include <stdio.h>

#include "help.h"

void help(char *cmd)
{
  printf("Usage Info:\n" 
            "%s --help\n" 
            "%s --file FILENAME\n" 
            "%s --list word1 word2 ...\n",
            cmd, cmd, cmd);
  
}