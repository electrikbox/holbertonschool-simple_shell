#include "main.h"

/**
 * main - Shell
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: 0
*/
int main(int argc, char **argv)
{
	int exitStatus = 0;
	char *input = NULL, *trimmedInput = NULL;
	size_t bufSize = 0;
	ssize_t read;

	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("ⓢ ");

		read = getline(&input, &bufSize, stdin);
		if (read == -1)
			break;

		trimmedInput = trimInput(input);
		if (trimmedInput == NULL)
			continue;

		if (strcmp(trimmedInput, "exit\n") == 0)
		{
			free(trimmedInput);
			exit(0);
		}

		exitStatus = execute(trimmedInput);
		if (exitStatus == -1)
			perror(argv[0]);
	}

	free(input);
	return (exitStatus);
}
