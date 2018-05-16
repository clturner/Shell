#include"shell.h"
/**
 * findpath - function to create full path argument
 * @tok_args: getline input that has been tokenized
 * Return: new argument with the completed path
 */
char **findpath(char **tok_args)
{
	dirset_t *head;
	dirset_t *tmp;
	char *buff;
	char *full_path;
	int status = 0;
	unsigned int mallocsize;

	head = tmp = path_link(&full_path);
	mallocsize =  ((_strlen(tok_args[0]) + _strlen(head->dir) + 2));
	while ((tmp != NULL) && (status == 0))
	{
		buff = malloc(sizeof(char) * mallocsize);
		if (buff == NULL)
			return (NULL);
		buff = _memset(buff, '\0', mallocsize);
		pathcat(buff, tmp->dir, tok_args);
		if (access(buff, X_OK) == 0)
		{
			status = 1;
			free(tok_args[0]);
			tok_args[0] = buff;
			free_path(head);
			free(full_path);
			return (tok_args);
		}
		else
			tmp = tmp->next;
		free(buff);
	}
	free_path(head);
	free(full_path);
	free_pointers(tok_args);
	return (NULL);
}
/**
 * path_link - function to return linked list of directories
 * @full_path: pointer to pointer of the path
 * Return: linked list of type dirset_t
 */
dirset_t *path_link(char **full_path)
{
	dirset_t *head;
	char *dir;

	head = NULL;
	*full_path = _getenv("PATH");

	dir = strtok(*full_path, ":");
	while (dir != NULL)
	{
		if (dir == NULL)
			break;
		add_node_end(&head, dir);
		dir = strtok(NULL, ":");
	}
	return (head);
}
/**
 * pathcat - function to concatonate the path
 * @dest: destination buffer
 * @dir: directory to be searched
 * @tok_args: tokenized input from command line
 * Return: char pointer to destination
 */
char *pathcat(char *dest, char *dir, char **tok_args)
{
	_strcpy(dest, dir);
	_strcat(dest, "/");
	_strcat(dest, tok_args[0]);
	return (dest);
}

/**
 * free_path - function to free list
 * @head: passed parameter pointer of struct
 * Return: void
 */
void free_path(dirset_t *head)
{
	dirset_t *traveler;

	while (head != NULL)
	{
		traveler = head;
		head = head->next;
		free(traveler->dir);
		free(traveler);
	}
}
/**
 * free_pointers - function to free double pointers
 * @ptr: pointer to pointer passed to be freed
 * Return: void
 */
void free_pointers(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
