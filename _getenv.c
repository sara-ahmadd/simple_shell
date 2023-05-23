#include "main.h"

/**
 * _getenv - get value of environment variable
 * @name: the name of the environment var
 *
 * Return: pointer to the value
 */


char *_getenv(char *name)
{
	list_t *curr;

	if (!vars_list)
	{
		return (NULL);
	}
	else
	{
		curr = vars_list;
		while (curr != NULL)
		{
			if (str_cmp(curr->var_name, name) == 0)
			{
				return (curr->var_value);
			}
			curr = curr->next;
		}
	}
	return (NULL);

}
