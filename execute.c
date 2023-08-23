#include "main.h"

/**
 * execute - Executes a command.
 * @input: The command to execute
 * Return: 1 on success, -1 on failure
*/
int execute(char *input)
{
	int status, exeitStatus = 0;
	char **args, *path;
	pid_t pid;

	args = tokenize(input);
	if (args == NULL)
		return (-1);

	if (input[0] == '/' || (input[0] == '.' && input[1] == '/'))
		path = strdup(input);
	else
		path = getPathEnv(args[0]);

	if (path == NULL)
	{
		free(args);
		return(-1);
	}

	pid = fork();
	if (pid < 0)
	{
		free(args);
		free(path);
		return(-1);
	}
	else if (pid == 0)
	{
		exeitStatus = execve(path, args, environ);
		if (exeitStatus < 0)
		{
			free(args);
			free(path);
			return (exeitStatus);
		}
	}
	else
	{
		wait(&status);
		free(args);
		free(path);
	}
	return (exeitStatus);
}
