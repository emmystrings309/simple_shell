#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

void execute_command(char *args[]);
int is_command_in_list(const char *command);
int is_command_in_lists(const char *command);
int run_script(void);

#endif