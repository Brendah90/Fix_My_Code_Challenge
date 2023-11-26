#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}
	for (p = 0; p < index && current != NULL; p++)
		current = current->next;
	if (current == NULL)
		return (-1);
	if (current->next == NULL)
	{
		current->prev->next = NULL;
		free(current);
		return (1);
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
	return (1);
}
