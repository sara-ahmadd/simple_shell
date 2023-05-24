#include "main.h"

/**
 * comm_handle - handle commands
 * @argv: list of arguments to program
 *
 * Return: void
 */

void comm_handle(char *argv[])
{
	if (str_cmp(argv[0], "env") == 0)
	{
		env_vars();
	}
	else if (str_cmp(argv[0], "printenv") == 0)
	{
		print_env(argv);
	}
	else if (str_cmp(argv[0], "setenv") == 0)
	{
		set_env(argv);
	}
	else if (str_cmp(argv[0], "unsetenv") == 0)
	{
		unset_env(argv);
	}
	else if (str_cmp(argv[0], "exit") == 0)
	{
		exit_builtin();
	}
	else if (str_cmp(argv[0], "cd") == 0)
	{
		change_dir(argv);
	}
	else
	{
		execcmd(argv);
	}
}
