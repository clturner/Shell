#include"shell.h"
/**
 * _getenv - returns the colon deliminated varible from evironment
 * @name: name of variable in the environment
 * Return: match
 */
char *_getenv(const char *name)
{
	const char *token;
	char *match;
	char **newenv;
	char **newenvtmp;

	newenvtmp = newenv = envcopy();
	match = malloc(sizeof(char) * BUFF_SIZE);
	if (match == NULL)
	{
		perror("Error: ");
		return (NULL);
	}
	while (*newenv)
	{
		token = strtok(*newenv, "=");
		while (token)
		{
			if (_strcmp(token, name) == 0)
			{
				token = strtok(NULL, "=");
				_strcpy(match, token);
				free_pointers(newenvtmp);
				return (match);
			}
			token = strtok(NULL, "=");
		}
		newenv++;
	}
	free_pointers(newenvtmp);
	return (NULL);
}
/**
 * envcopy - function to create copy of environ
 * @void: accepts no parameters
 * Return: a double pointer of type char
 */
char **envcopy(void)
{
	int i = 0;
	char **newenv;

	newenv = malloc(sizeof(char *) * TOK);
	if (newenv == NULL)
	{
		perror("Error: ");
		return (NULL);
	}
	while (environ[i] != NULL)
	{
		newenv[i] = _strdup(environ[i]);
		i++;
	}
	newenv[i] = NULL;
	return (newenv);
}
