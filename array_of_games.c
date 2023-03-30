#include <stdio.h>

#include "startup.h"
#include "play.h"
#include "shutdown.h"
#include "array_of_games.h"

char *array_of_games_get_title()
{
  return "Array of Games Program";
}

int array_of_games_play(void) {
  startup();
  play2();
  shutdown();
  return 0;
}