#include "main.h"

/**
 * main - Shell
 * @ac: Number of arguments
 * @av: Arguments
 * Return: 0
*/
int main(int ac, char **av)
{
	int exe;
	char *input;
	size_t bufsize;

	(void)ac;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		input = NULL;
		bufsize = 0;

		if (getline(&input, &bufsize, stdin) == -1)
			break;

		if (*input == '\n')
			continue;

		exe = execute(input);
		if (exe == -1)
			perror(av[0]);
	}
	free(input);
	return (0);
}
