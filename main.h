#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <termios.h>


#define MAX_HISTORY 150
#define MAX_CHAR 100


/**
 * struct list_s - singly linked list
 * @var_name: variable name - (malloc'ed string)
 * @var_value: value of the environment var
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *var_name;
	char *var_value;
	struct list_s *next;
} list_t;

/*list of environment variables*/
extern char **environ;

void start_shell(void);
void init(void);
void env_vars(char *argv[]);
void comm_handle(char *argv[]);
int change_dir(char *argv[]);
void exit_builtin(char *argv[]);
int execcmd(char **argv);
char *_getenv(const char *name);
char *getPath(char *command);
int my_system(char *command);
int set_env(char **argv);
int unset_env(char **argv);
void print_env(char *argv[]);

/*linked list functions*/
list_t *insert_node_end(list_t **root, char *str1, char *str2);
list_t *environ_vars_list(void);
int remove_node(char *var_name);
list_t *vars_list;

#endif
