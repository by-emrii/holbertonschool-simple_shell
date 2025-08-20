#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* global variable */
extern char **environ;

/* prototypes */
int execute(char **args, char *progname, int line_count);
char **parse_line (char *line);
char *get_full_path(char *command);
int handle_builtin_cmds(char **args);
#endif
