// ascii_char_game.c - IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ascii_char_game.h"

static char ascii_table[128] = { 0 };

// Dec 0-9
// hex 0-f, 0123456789abcdef
static void init_table()
{
  ascii_table[48] = '0';
  ascii_table[49] = '1';
  ascii_table[0x32] = '2';
  ascii_table[0x33] = '3';
  ascii_table[0x34] = '4';
  ascii_table[0x35] = '5';
  ascii_table[0x36] = '6';
  ascii_table[0x37] = '7';
  ascii_table[0x38] = '8';
  ascii_table[0x39] = '9';
}

// Return the title of the game
char *ascii_c_get_title()
{
  return "Guess ASCII Keyboard";
}

static int get_random_index()
{
  //return 0x35;
  time_t now = time(NULL);
  srand(now);
  int choice = rand() % 10;
  // SInce we are only using digits 0-9 we offset the random number by 0x30
  return 0x30 + choice;
}

// Return the score
// 0 is no score, i.e. lost the game
int ascii_c_play()
{
  // Initialize ascii table
  init_table();
  int answer = get_random_index();
  printf("ASCII value of 0x%x is what char: ", answer);
  int playing = 1; // 1=true
  do
    {
      char choice;
      scanf("%c", &choice);
      if (choice == ascii_table[answer])
      {
        printf("Correct!\n");
        playing = 0;
      }
      else
      {
        printf("Try again");
      }
      // Eat the new line character
      scanf("%c", &choice);
    }
    while(playing);
  
  return 0;
}