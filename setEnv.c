#include "main.h"
/**
 * set_env - set an environment variable
 * @argv: list of arguments to the program
 *
 * Return: 1
 */

int set_env(char *argv[])
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		fprintf(stderr, "Too few arguments.\n");
		return (-1);

	}
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		perror("Error ");
	}
	return (1);
}

/**
 * unset_env - remove an environment variable
 * @argv: list of arguments to the program
 *
 * Return: 1
 */

int unset_env(char *argv[])
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, "Too few arguments");
		return (-1);
	}
	if (getenv(argv[1]) != NULL)
	{
		unsetenv(argv[1]);
		return (1);
	}
	else
	{
		perror("Variable doesnot exist");
	}
	return (1);
}

/**
 * print_env - print environment vars
 * @argv: list of arguments to the program
 */
void print_env(char *argv[])
{
	char *name;
	int i = 0;

	if (strcmp(argv[0], "printenv") == 0 && argv[1] == NULL)
	{
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
	}
	name = getenv(argv[1]);
	if (name == NULL)
	{
		exit(0);
	}
	else
	{
		printf("%s\n", name);
	}
}
