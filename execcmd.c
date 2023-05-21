#include "shell.h"

/**
 * execcmd - execute the command
 * @argv: the array of arguments
 * Return: 1 on success
 */

int execcmd(char *argv[])
{
	char *cmd = NULL, *path;
	int x;
	pid_t pid;

	if (argv[0] != NULL)
	{
		pid = fork();
	}
	if (pid == -1)
	{
		perror("Error with fork.");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		cmd = argv[0];
		path = getPath(cmd);
		x = execve(path, argv, NULL);
		if (x == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (1);
}
