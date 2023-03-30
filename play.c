// play.c
// The IMPLEMENTATION

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "play.h"

void play(char **word_list, int list_size)
{
  printf("Guess What Word from these words!\n");
 
  for (int i = 0; i < list_size; i++)
  {
    printf("%d-%s ", i, word_list[i]);
  }
  
  printf("\n");

  int num_tries = 0;
  srand(time(NULL)); // See the random number generator

  //printf("list_size: %d\n", list_size);
  int goal = rand() %list_size;
  printf("goal: %d\n", goal);

  int choice;
  
  do
  {
    num_tries++;
    printf("Your choice: ");
    scanf("%d", &choice);
  } while ((goal != choice) && (num_tries < 3));

  if (goal != choice)
  {
    printf("Sorry you lost!\n");
  }
  else
  {
    printf("You win!\n");
  }
}
