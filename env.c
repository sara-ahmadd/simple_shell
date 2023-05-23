#include "main.h"

/**
 * env_vars - return value of environment variable
 * @argv: list of input arg
 *
 * Return: value
 */

void env_vars(char *argv[])
{
	list_t *curr;
	char cwd[200];

	if (strcmp(argv[0], "env") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("Error");
		}
		for (curr = vars_list; curr != NULL; curr = curr->next)
		{
			if (strcmp(curr->var_name, "PWD") == 0)
			{
				curr->var_value = strdup(cwd);
			}
			printf("%s=%s\n", curr->var_name, curr->var_value);
		}
	}
}
