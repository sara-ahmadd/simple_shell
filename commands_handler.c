#include "main.h"

/**
 * comm_handle - handle commands
 * @argv: list of arguments to program
 *
 * Retrun: void 
 */
void comm_handle(char *argv[])
{

	if (strcmp(argv[0], "cd") == 0)
	{
		change_dir(argv);
	}
	else 
	{
		execcmd(argv);
	}
}
/**
 * change_dir - change directory
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int change_dir(char *argv[])
{
	if (argv[1] == NULL)
	{
		chdir(getenv("HOME"));
		return (1);
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			printf("%s: no such directory is found.\n", argv[1]);
			return (-1);
		}
	}
	return (0);
}
