#include "main.h"


/**
 * insert_node_end - add node at the end of the list
 * @root: the head of the list
 * @str1: name of the var
 * @str2: value of the var
 *
 * Return: void
 */

list_t *insert_node_end(list_t **root, char *str1, char *str2)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *curr;

	if (new_node == NULL || root == NULL)
		exit(1);
	new_node->next = NULL;
	if (str1)
	{
		new_node->var_name = str_dup(str1);
		if (!new_node->var_name)
		{
			free(new_node);
			exit(1);
		}
	}
	if (str2)
	{
		new_node->var_value = str_dup(str2);
		if (!new_node->var_value)
		{
			free(new_node);
			exit(1);
		}
	}
	curr = *root;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	return (new_node);
}

/**
 * environ_vars_list - copy env vars to a linked list
 *
 * Return: the created linked list
 */

list_t *environ_vars_list(void)
{
	list_t *root = malloc(sizeof(list_t));
	int i;
	char *token = NULL, *tok_2;

	token = strtok(environ[0], "=");
	tok_2 = strtok(NULL, "=");
	root->next = NULL;
	root->var_name = token;
	root->var_value = tok_2;

	for (i = 1; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		tok_2 = strtok(NULL, "=");
		insert_node_end(&root, token, tok_2);
	}
	return (root);
}


/**
 * remove_node - remove a node from the list
 * @var_name: the value to be removed
 *
 * Return: 1
 */

int remove_node(char *var_name)
{
	list_t *curr;

	if (vars_list == NULL || var_name == NULL)
	{
		return (-1);
	}
	for (curr = vars_list; curr->next != NULL; curr = curr->next)
	{
		if (str_cmp(curr->next->var_name, var_name) == 0)
		{
			list_t *temp = curr->next;

			curr->next = curr->next->next;
			free(temp);
			return (1);
		}
	}
	return (1);
}
