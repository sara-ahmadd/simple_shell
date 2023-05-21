#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


char *currentDirectory;
int init_mode;
extern char **environ;

void init();
int execcmd(char **argv);
char *getPath(char *command);
void exit_shell(char *argv[]);
int change_dir(char *argv[]);
int commands_handler(char *argv[]);
void env_vars(char *argv[]);
int set_env(char **argv);
int unset_env(char **argv);
void print_env(char *argv[]);
#endif
