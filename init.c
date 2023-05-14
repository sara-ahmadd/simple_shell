#include "main.h"

/**
 * start_shell - print the prompt on starting the shell
 */

void startShell()
{
	char *prompt = "(simple_shell:)";
	printf("%s", prompt);
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
