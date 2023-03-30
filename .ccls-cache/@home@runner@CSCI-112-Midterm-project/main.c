#include <stdio.h>

#include "startup.h"
#include "menu.h"
#include "shutdown.h"

int main(int argc, char **argv)
{
  startup();
  menu(argc, argv);
  shutdown();
  return 0;
}