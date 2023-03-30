#include <stdio.h>

#include "welcome.h"
#include "cli.h"
#include "play.h"
#include "guess_what.h"

char *guess_what_get_title()
{
  return "Guess What Program";
}

int guess_what_menu(int argc, char **argv) 
{
  welcome();
  cli_init(argc, argv);
  play(cli_get_list(), cli_get_list_size());
  return 0;
}