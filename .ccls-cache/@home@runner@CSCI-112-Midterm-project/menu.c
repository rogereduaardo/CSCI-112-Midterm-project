// menu.c - IPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "hello_world.h"
#include "mileage_reimbursement.h"
#include "calculator.h"
#include "food_menu.h"
#include "loop_d_loo.h"
#include "guess_what.h"
#include "array_of_games.h"

#define EXIT_MENU -1

static char *programs[7] = { 0 };

static void display_menu_choices()
{
  // Title
  printf("\nMenu:\n");
  // Initialize the array
  programs[0] = hello_world_get_title();
  programs[1] = mileage_reimbursement_get_title();
  programs[2] = calculator_get_title();
  programs[3] = food_menu_get_title();
  programs[4] = loop_d_loo_get_title();
  programs[5] = guess_what_get_title();
  programs[6] = array_of_games_get_title();
  

  int num_array_entries = sizeof(programs) / sizeof(programs[0]);
  for (int i = 0; i < num_array_entries; i++)
    {
      printf("\n%d - %s\n", i, programs[i]);
    }
  printf("\nSelect number or %d to exit: ", EXIT_MENU);
}

static int get_our_menu_choices()
{
  int choice;
  scanf("%d", &choice);
  // Eat the new line
  char c;
  scanf("%c", &c);
  return choice;
}

void menu(int argc, char **argv)
{
  while (1)
    {
      display_menu_choices();
      int choice = get_our_menu_choices();
      if (choice == EXIT_MENU)
        break;
      switch(choice)
        {
          case 0: hello_world_menu(); break;
          case 1: mileage_reimbursement_menu();break;
          case 2: calculator_menu(); break;
          case 3: food_menu_menu(); break;
          case 4: loop_d_loo_menu(argc, argv); break;
          case 5: guess_what_menu(argc, argv); break;
          case 6: array_of_games_play(); break;
        }
    }
}
