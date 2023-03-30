// play.c - INOLEMENATTION

#include <stdio.h>

#include "play2.h"
#include "ascii_char_game.h"
#include "ansi_c_game.h"
#include "tic_tac_toe.h"
#include "array_of_games.h"

#define GAME_EXIT -1
// File scope
/*
static char *games[] =
{
  "Guess ASCII Char Game",
  "Guess ANSI C Keyboard",
  "Tic-Tac-Toe", //"1", "2", "3"
};
*/

static char *games[3] = { 0 };


static void display_menu_choices()
{
  // Initialize the array
  games[0] = ascii_c_get_title();
  games[1] = ansi_c_get_title();
  games[2] = tic_tac_toe_get_title();
    
  //puts("TODO: DISPLAY MENU CHOICES");
  int num_array_entries = sizeof(games) / sizeof(games[0]);
  printf("num_array_entries: %d\n", num_array_entries);
  for (int i = 0; i < num_array_entries; i++)
    {
      printf("%d - %s\n", i, games[i]);
    }
  printf("Select number or %d to exit: ", GAME_EXIT);
}

static int get_our_menu_choices()
{
  int choice; // local scope
  scanf("%d", &choice);
  // Eat the new line
  char c;
  scanf("%c", &c);
  return choice;
}

void play2()
{
  //printf("%s\n", __FUNCTION__);
  while (1)
    {
      display_menu_choices();
      int choice = get_our_menu_choices();
      if (choice == GAME_EXIT)
        break;
      //puts("TODO: Handle game");
      switch(choice)
        {
          case 0: ascii_c_play(); break;
          case 1: ansi_c_play();break;
          case 2: tic_tac_toe_play();break;
        }
    }
}

