#include "main.h"





/**
 * start_shell - starting msg to my shell
 */

void start_shell(void)
{
	char *prompt = "(Myshell:)";
	char *currentDirectory = NULL;

	printf("%s>%s# ", prompt, getcwd(currentDirectory, 1024));
}
/**
 * change_dir - change directory
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int change_dir(char *argv[])
{
	if (argv[1] == NULL)
	{
		chdir(_getenv("HOME"));
		return (1);
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		chdir("/");
		return (1);
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			printf("%s: no such directory is found.\n", argv[1]);
			return (-1);
		}
	}
	return (0);
}


/**
 * tokenize - split string input into tokens
 * @argv: the input string
 * @chars_read: number of characters
 * @lineptr: pointer to the entered line
 * @linecpy: copy of the entered line
 *
 * Return: the tokens resulted
 */

char **tokenize(char *argv[], ssize_t chars_read, char *lineptr, char *linecpy)
{
	char *token;
	const char *delims;
	ssize_t tokens_count = 0, i, j;

	delims = " \n";
	linecpy = malloc(sizeof(char) * chars_read);
	if (linecpy == NULL)
		free(lineptr);
	strcpy(linecpy, lineptr);
	token = strtok(lineptr, delims);
	while (token != NULL)
	{
		tokens_count++;
		token = strtok(NULL, delims);
	}
	tokens_count++;
	argv = malloc(sizeof(char *) * tokens_count);
	if (argv == NULL)
	{
		free(linecpy);
		free(lineptr);
		exit(0);
	}
	token = strtok(linecpy, delims);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		if (argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			free(linecpy);
			free(lineptr);
			exit(0);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, delims);
	}
	return (argv);
}


/**
 * main - the entery point to the program
 * @argc: number of arguments entering to the program
 * @argv: array containing the arguments
 *
 * Return: zero if success or non-zero value on failure
 */

int main(int argc, char **argv)
{
	ssize_t chars_read;
	size_t n;
	char *lineptr = NULL, *linecpy = NULL;
	char *currentDirectory = (char *) calloc(1024, sizeof(char));

	vars_list = environ_vars_list();
	(void)argc;
	n = 0;
	while (1)
	{
		init();
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			printf("Exit Myshell\n");
			free(lineptr);
			return (-1);
		}
		argv = tokenize(argv, chars_read, lineptr, linecpy);
		if (argv[0] == NULL)
			continue;
		comm_handle(argv);
		free(linecpy);
		free(argv);
	}
	free(lineptr);
	free(currentDirectory);
	return (0);
}
