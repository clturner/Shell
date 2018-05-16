#include "shell.h"
/**
 * main - function to run the shell
 * @void: no paramters accepted
 * Return: integer
 */
int main(void)
{
	char *line;
	size_t linelen;
	ssize_t len_line;
	char **tok_args;

	while (1)
	{
		line = NULL;
		len_line = 0;
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		len_line = getline(&line, &linelen, stdin);
		if (_strcmp(line, "exit") == 0)
			break;
		if (charline(line) == 0)
			continue;
		if (line[len_line - 1] == 0)
			break;
		line[len_line - 1] = '\0';
		tok_args = tokenizer(line);
		if (accesscheck(tok_args) != 0)
			tok_args = findpath(tok_args);
		if (tok_args == NULL)
		{
			perror("command not found");
			free(line);
			continue;
		}
		forkexec(tok_args);
		free_pointers(tok_args);
		free(line);
	}
	free(line);
	return (0);
}

/**
 * charline - function to check if line input is character
 * @line: input from command line via getline
 * Return: 0 if matching character, -1 if not
 */
int charline(char *line)
{
	if (_strcmp(line, " ") == 0 || _strcmp(line, "\t") == 0 ||
	    _strcmp(line, "\n") == 0)
	{
		free(line);
		return (0);
	}
	return (-1);
}

/**
 * forkexec - function to execute commands
 * @tok_args: command to be executed
 * Return: 0 on success
 */
int forkexec(char **tok_args)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid < 0)
		perror("Error: ");
	else if (pid == 0)
		execve(tok_args[0], tok_args, environ);
	else
		wait(&status);
	return (0);
}

/**
 * accesscheck - function to check whether path is already complete
 * @tok_args: tokenized argument entered in command line
 * Return: 0 if path is complete, -1 if it is not
 */
int accesscheck(char **tok_args)
{
	if (access(tok_args[0], X_OK != 0))
		return (-1);
	return (0);
}
