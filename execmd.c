#include "main.h"

/**
 * execmd - Executes a command
 * @argv: The command to execute
*/

void execmd(char **argv)
{
	int execute;
	int status;
	pid_t pid = fork();

	char *command = NULL;

	if (pid < 0)
	{
		perror("Fork Failed");
		exit(1);
	}

	else if (pid == 0)
	{
		command = argv[0];
		execute = execve(command, argv, NULL);

		if (execute == -1)
			perror("Error");
	}

	else
		wait(&status);
}
