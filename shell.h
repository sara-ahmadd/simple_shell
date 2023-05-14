#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void init();
void execcmd(char **argv);
char *getPath(char *command);
void exit_shell(char *argv[]);
#endif
