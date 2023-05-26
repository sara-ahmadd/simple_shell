#include "main.h"


/**
 * is_delim - get delims
 * @c: chars string
 * @delim: delimiters
 *
 * Return: unsigned integer
 */
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
		return (1);
		delim++;
	}
	return (0);
}

/**
 * my_strtok - strtok() implementation
 * @srcString: string to tokenize
 * @delim: delimiters
 *
 *
 * Return: pointer to string
 */

char *my_strtok(char *srcString, char *delim)
{
	static char *backup_string;
	char *ret = srcString;

	if (!srcString)
	{
		srcString = backup_string;
	}
	if (!srcString)
	{
		return (NULL);
	}
	while (1)
	{
		if (is_delim(*srcString, delim))
		{
			srcString++;
			continue;
		}
		if (*srcString == '\0')
		{
			return (NULL);
		}
		break;
	}
	while (1)
	{
		if (*srcString == '\0')
		{
			backup_string = srcString;
			return (ret);
		}
		if (is_delim(*srcString, delim))
		{
			*srcString = '\0';
			backup_string = srcString + 1;
			return (ret);
		}
		srcString++;
	}
}

