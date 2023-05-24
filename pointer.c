#include "main.h"

/**
 * free_list - function that frees a list_t list
 * @head: pointer to the head of the list
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->var_name);
		free(temp->var_value);
		free(temp);
	}
}
