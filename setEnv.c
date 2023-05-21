#include "shell.h"

/**
 * set_env - set an environment variable
 * @argv: list of arguments to the program
 *
 * Return: 1
 */

int set_env(char *argv[])
{

	if (argv[1] == NULL || argv[2] == NULL || setenv(argv[1], argv[2], 1) != 0)
	{
		write(STDERR_FILENO, "Few arguments or somthing went wrong\n", 50);
		return (-1);

	}
	return (-1);
}

/**
 * unset_env - remove an environment variable
 * @argv: list of arguments to the program
 *
 * Return: 1
 */

int unset_env(char *argv[])
{
	if (argv[1] == NULL || getenv(argv[1]) == NULL)
	{
		write(STDERR_FILENO, "Too few arguments\n", 50);
		return (-1);
	}
	else if (getenv(argv[1]) != NULL)
	{
		unsetenv(argv[1]);
		return (1);
	}
	return (-1);
}

/**
 * print_env - print environment vars
 * @argv: list of arguments to the program
 */

void print_env(char *argv[])
{
	char *name;
	int i;

	name = getenv(argv[1]);

	if (strcmp(argv[0], "printenv") == 0)
	{
		if (argv[1] == NULL)
		{
			for (i = 0; environ[i] != NULL; i++)
			{
				printf("%s\n", environ[i]);
			}
		}
	}
	if (name != NULL)
	{
		printf("%s\n", name);
	}

}
