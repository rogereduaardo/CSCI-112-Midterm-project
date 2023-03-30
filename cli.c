// cli.c
// The IMPLEMENTATION 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cli.h"
#include "help.h"

// Make variable File Scope
// Only see the value in this file
// Data Hiding
static int list_size;
int cli_get_list_size()
{
  return list_size;
}
// Default: Global Access scope
// USe "static" to make it file scopes

/* static char *test_words[] =
{
  "one", "two", "three"
}; */

// File Scope
// Data Hiding
static char **list;
char **cli_get_list()
{
   return list;
} 

void cli_init(int argc, char *argv[])
{
  // If we only have command
  if(1 == argc)
  {
    help(argv[0]);
    return;
  }
  // Check for the "--" option
  char *dash_cmd = argv[1]; //Local Scope
  //printf("dash_cmd: %s\n", dash_cmd);
  if(0 == strcmp("--list", dash_cmd))
  {
    //puts("Handle __list");
    //Verify at least 3 words

    if (argc < 5)
    {
      fprintf(stderr, "Not enough arguments!\n");
      // For now, just exit
      exit(1);
    }
    // Set the list size and the list
    list_size = argc - 2; // subtract ./main and --list
    list = &argv[2];
    return;
  }
  if (0 == strcmp("--file", dash_cmd))
  {
    //puts("Handle --file");
    // Make sure we have a filename
    if (argc != 3)
    {
      fprintf(stderr, "Must have filename!\n");
      exit(3);
    }

    // Open the file
    char *filename = argv[2];
    FILE *file = fopen(filename, "r"); //Read only
    if (NULL == file)
    {
      perror("fopen");
      exit(4);
    }
    // Read each entry in file
    char word[10];
    //Read the first word
    int result = fscanf(file, "%s", word);
    printf("result: %d\n", result);
    while (result != EOF) // EOF = End of File
      {
        printf("%s\n", word);
        result = fscanf(file, "%s", word);
        printf("result: %d\n", result);
        //exit(10);
      }

    // Close the file
    fclose(file);
      
    return;
  }
  help(argv[0]);
}
