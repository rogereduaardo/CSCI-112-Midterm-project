// hello_world.c - IMPLEMENTATION

#include <stdio.h>

#include "hello_world.h"

// Return title of the program
char *hello_world_get_title()
{
  return "Hello World Program";
}

int hello_world_menu()
{
  printf("\n*********************************************\n");
  printf("\nHello World From C\n");
  printf("Program Written by Roger Martinez\n");
  printf("\n*********************************************\n");
  
  return 0;
}