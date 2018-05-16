#include "shell.h"

/**
 * add_node_end - function to add node to end of list
 * @head: double pointer passed
 * @dir: const char string passed
 * Return: address of new element or NULL if failed
 */
dirset_t *add_node_end(dirset_t **head, const char *dir)
{
	dirset_t *endnode;
	dirset_t *travelnode;

	if (head == NULL)
		return (NULL);

	endnode = malloc(sizeof(dirset_t));

	if (endnode == NULL)
		return (NULL);
	endnode->dir = _strdup(dir);
	endnode->next = NULL;

	if (*head == NULL)
	{
		*head = endnode;
		return (endnode);
	}
	travelnode = *head;
	while (travelnode->next != NULL)
		travelnode = travelnode->next;
	travelnode->next = endnode;
	return (endnode);
}
