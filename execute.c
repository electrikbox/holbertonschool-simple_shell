#include "main.h"

/**
 * execute - Executes a command.
 * @input: The command to execute
 * Return: 1 on success, -1 on failure
*/
int execute(char *input)
{
	int status, exe;
	char **args, *path, *trimmedInput;
	pid_t pid;

	trimmedInput = trimInput(input);
	args = tokenize(input);

	if (trimmedInput[0] == '/')
		path = strdup(trimmedInput);
	else
		path = getPathEnv(args[0]);

	if (args == NULL || path == NULL)
		return (-1);

	pid = fork();

	if (pid < 0)
	{
		free(args);
		free(path);
		return(-1);
	}
	else if (pid == 0)
	{
		exe = execve(path, args, environ);
		if (exe < 0)
		{
			free(args);
			free(path);
			return (-1);
		}

		exit(1);
	}
	else
	{
		wait(&status);
		free(args);
		free(path);
	}

	return (1);
}
