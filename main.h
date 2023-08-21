#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

extern char **environ;

int execute(char *input);
char *getPathEnv(char *input);
char **tokenize(char *input);
char *trimInput(char *input);

#endif
