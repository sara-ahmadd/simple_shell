#include "main.h"

/**
 * set_env - set an environment variable
 * @argv: list of arguments to the program
 *
 * Return: 1
 */

int set_env(char *argv[])
{
	list_t *node, *curr;

	if (argv[1] == NULL || argv[2] == NULL || vars_list == NULL)
	{
		write(STDERR_FILENO, "too few arguments\n", 18);
		return (-1);

	}
	else
	{
		for (curr = vars_list; curr != NULL; curr = curr->next)
		{
			if (str_cmp(curr->var_name, argv[1]) == 0)
			{
				str_cpy(curr->var_value, argv[2]);
				return (1);
			}
		}
		node = insert_node_end(&vars_list, argv[1], argv[2]);
		if (node == NULL)
		{
			write(STDERR_FILENO, "something went wrong\n", 20);
			return (-1);
		}
		else
		{
			return (1);
		}
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
	char *var;

	if (argv[1] == NULL)
	{
		write(STDERR_FILENO, "Too few arguments\n", 18);
		return (-1);
	}
	var = _getenv(argv[1]);

	if (var != NULL)
	{
		remove_node(argv[1]);
	}
	else
	{
		return (-1);
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
	list_t *curr;

	if (argv[1] == NULL)
	{
		for (curr = vars_list; curr != NULL; curr = curr->next)
		{
			printf("%s=%s\n", curr->var_name, curr->var_value);
		}
	}
	if (argv[1] != NULL)
	{
		name = _getenv(argv[1]);
		if (name == NULL)
		{
			return;
		}
		printf("%s\n", name ? name : NULL);
	}

}
