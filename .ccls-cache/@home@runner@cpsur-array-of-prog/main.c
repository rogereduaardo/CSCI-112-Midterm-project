#include <stdio.h>

#include "startup.h"
#include "menu.h"
#include "shutdown.h"

int main(void) {
  startup();
  menu();
  shutdown();
  return 0;
}