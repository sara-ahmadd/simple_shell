#include "shell.h"

/**
 * startShell - print the prompt on starting the shell
 */

void startShell()
{
	char prompt [100]= "(simple_shell:)";
	write(STDOUT_FILENO,&prompt, 100);
}


/**
 * init - initialize the shell
 */

void init()
{
	init_mode = isatty(STDIN_FILENO);
	
	if (init_mode == 1)
	{
		startShell();
	}
}
