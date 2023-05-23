#include "main.h"

/**
 * exit_builtin - exit the shell
 * @argv: list of arguments
 *
 * Return: void
 */

void exit_builtin(char *argv[])
{
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
}
