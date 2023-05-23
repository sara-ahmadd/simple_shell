#include "main.h"



/**
 * str_len - print length of string
 * @str: the string
 * Return: length
 */

int str_len(char *str)
{
	int i = 0;

	if (!str)
	{
		return (0);
	}
	while (*str++)
	{
		i++;
	}
	return (i);
}



/**
 * str_cpy - copy string to another
 * @dest: place to copy into
 * @src: place to copy from
 *
 * Return: pointer to destination
 */

char *str_cpy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * str_cmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: integer 1 or 0 or -1
 */

int str_cmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
			continue;
		else
			break;
	}
	if (s1[i] == s2[i])
		return (0);
	if ((s1[i] | 32) < (s2[i] | 32))
		return (-1);
	return (1);
}

/**
 * str_dup - duplicates a string
 * @src: the string to be duplicated
 *
 * Return: pointer to the duplicated string
 */

char *str_dup(char *src)
{
	char *str;
	char *cp;
	int len, i = 0;

	len = str_len(src);
	str = malloc(len + 1);

	if (!str)
		return (NULL);
	cp = str;

	while (src[i] != '\0')
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (str);
}

/**
 * str_cat - concatenate two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to concatenated string
 */

char *str_cat(char *s1, char *s2)
{
	int i = 0, j = 0;

	while (s1[i] != '\0')
	{
		i++;
	}

	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

