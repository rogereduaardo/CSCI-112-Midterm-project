// loop_d_loo.c - IMPLEMENTATION

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "loop_d_loo.h"

#define PROGRAM_NAME "Loop-D-Loo"
#define VERSION "3.0.0" //Major/Minor/Bug-Fix
#define DEVELOPER "Roger Martinez"

#define START_NUM_NIM 1
#define START_NUM_MAX 10

#define END_NUM_MIN 10
#define END_NNUM_MAX 100

void display_startup_info()
{
  puts(PROGRAM_NAME);
  printf("\nVersion %s\n", VERSION);
  printf("\nProgram by %s\n", DEVELOPER);

  // Display Startup Time
  time_t now;
  time(&now);
  char *s = ctime(&now);
  printf("%s", s);
  // - Program Name
  // - Version
  // - Developer
  // - Startup time
 
}
// Return title of the program
char *loop_d_loo_get_title()
{
  return "Loop D Loop Program";
}

// Promt to contiue
// Return 0 to continue
// Return 1 to not continue
int promt_continue()
{
  printf("\nDo you want to continue (y/n)? ");
  int c = getchar();
  getchar(); //Eat the new line
  if ((c == 'y') ||(c == 'Y'))
    return 0;
    return 1;
  
}

void prompt_for_numbers(int *start_number, int *end_number)
  {
  //*start_number = 123;
  //*end_number = 456;
    if (start_number){
      printf("\nEnter start number from %d to %d: ", START_NUM_NIM, START_NUM_MAX);
      scanf("%d", start_number);
     if((*start_number < START_NUM_NIM) || (*start_number > START_NUM_MAX))
      {
      puts("\nNumber not in rage");
        exit(1);
      }
    }  
    
     printf("\nEnter end number from %d to %d: ", END_NUM_MIN, END_NNUM_MAX);
    scanf("%d", end_number);
    if((*end_number < END_NUM_MIN) || (*end_number > END_NNUM_MAX))
      {
      puts("\nNumber not in rage");
        exit(2);
      }
  }

// Handle the command-line
// handle_comand_line(argc, argv, &start_number, &end_number)
void handle_comand_line(int argc, char *argv[], int *start_number, int *end_number)
  {
  // If no command-liner args other than the command
    if (argc == 1) 
      return;
    if (argc < 3)
    {
      puts("Not enough args");
      return;
    }
    // Handle First Argument
    if (strcmp("--start", argv[1]) == 0)
    {
      *start_number = atoi(argv[2]);
    }
  }

int loop_d_loo_menu(int argc, char **argv)
{
  display_startup_info();

  // - Continiue?
  if (promt_continue())
  {
    puts("\nOK. Goodbye");
    return 0;
  }

  // Demo for()
  puts("for loop:");
  for (int i = 0; i < argc; i++)
    {
      printf("argv[%d]: %s\n", i, argv[i]);
    }
  
  // Demo while()
  puts("while loop:");
  int j = 0;
  while (j < argc)
    {
      printf("argv[%d]: %s\n", j, argv[j]);
      j++;
    }
  
  // Demo do while()
  puts("do while loop");
  j = 0;
  do 
    {
      printf("argv[%d]: %s\n", j, argv[j]);
      j++;
    }
    while(j < argc);

  // Starting number from 1-10
  // Endig nnumber 10-100
  int start_number = 0;
  int end_number = 0;

  // Handle the comand-line
  handle_comand_line(argc, argv, &start_number, &end_number);
  
  // Prompt the user for numbers 
  if (0 == start_number)
  {
  prompt_for_numbers(&start_number, &end_number);
  /* printf("\nstart_number: %d\n", start_number);
  printf("end_number: %d\n\n", end_number); */
  }
  else if (0 != start_number)
  {
    prompt_for_numbers(NULL, &end_number);
  }
  
  // Use the numbers to demo for, while, do-whle
  for (int i = start_number; i <= end_number; i++)
    {
      printf("%d ", i);
    }
printf("\n");

  j = start_number;
  while (j <= end_number)
    {
       printf("%d ", j);
      j++;
    }
  printf("\n");

  j = start_number;
  do
    {
        printf("%d ", j);
      j++;
    }
    while (j <= end_number);
  printf("\n");
  
  puts("\nAll done!");
  
  return 0;
}