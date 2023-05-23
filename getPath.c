#include "main.h"

/**
 * helper - helper function
 * @file_path: path to a file
 * @command: the entered command by the user
 * @token: tokenized string
 */

void helper(char *file_path, char *command, char *token)
{
	strcpy(file_path, token);
	strcat(file_path, "/");
	strcat(file_path, command);
	strcat(file_path, "\0");
}


/**
 * getPath - get the path of the entered command
 * @command: the entered command by the user
 *
 * Return: the path for the entered command
 */

char *getPath(char *command)
{
	char *path, *env, *path_copy, *token, *file_path;
	int i, j, cmd_len, token_len;
	struct stat buff;

	env = "PATH";
	path = _getenv(env);
	if (!path)
	{
		dprintf(STDERR_FILENO, "The entered variable %s is not found.\n", env);
		exit(1);
	}
	cmd_len = strlen(command);
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		token_len = strlen(token);
		file_path = malloc(token_len + cmd_len + (2 * sizeof(char)));
		helper(file_path, command, token);
		i = stat(file_path, &buff);
		if (i == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	j = stat(command, &buff);
	if (j == 0)
		return (command);
	return (NULL);

}
