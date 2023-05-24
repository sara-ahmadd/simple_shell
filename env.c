#include "main.h"
/**
 * env_vars - return value of environment variable
 *
 * Return: value
 */

void env_vars(void)
{
	int i;
	char cwd[200];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("Error");
	}
	else
	{
		setenv("PWD", cwd, 1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
