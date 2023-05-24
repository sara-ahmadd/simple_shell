#include "main.h"


/**
 * init - initialize the shell
 */

void init(void)
{
	int init_mode;

	init_mode = isatty(STDIN_FILENO);

	if (init_mode == 1)
	{
		start_shell();
	}
}
