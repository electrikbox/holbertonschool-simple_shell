#include "main.h"

/**
 * execute - Executes a command
 * @input: The command to execute
 * Return: 1 on success, -1 on failure
*/
int execute(char *input)
{
	int status, exe;
	char **args;
	pid_t pid;

	args = tokenize(input);
	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		free(args);
		exit(1);
	}
	else if (pid == 0)
	{
		exe = execve(args[0], args, environ);
		if (exe < 0)
		{
			free(args);
			return (-1);
		}

		exit(1);
	}
	else
	{
		wait(&status);
		free(args);
	}

	return (1);
}
