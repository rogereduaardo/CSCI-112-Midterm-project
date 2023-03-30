// cli.h - Command-Line Interface
// The INTERRFACE

#ifndef __CLI__
#define __CLI__

// API - Applications Programming Interface
// Initialize the CLI
void cli_init(int argc, char *argv[]);

int cli_get_list_size();
char **cli_get_list();

#endif