#include "shell.h"

/**
 * exit_shell - exit the shell
 * @argv: list of arguments
 *
 * Return: void
 */

void exit_shell(char *argv[])
{
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
}
