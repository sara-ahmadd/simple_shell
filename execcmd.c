#include "main.h"

/**
 * execcmd - execute the command
 * @argv: the array of arguments
 */

void execcmd(char *argv[])
{
	char *cmd = NULL, *path;
	char comm[100];
	int x;

	if (argv)
	{
		cmd = argv[0];
		path = getPath(cmd);
		x = execve(path, argv, NULL);
		if (x == -1)
		{
			strcpy(comm, argv[0]);
			perror("Error: ");
		}
	}
}
