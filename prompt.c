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
	char *input = NULL;
	size_t bufsize = 0;

	(void)ac;

	while (1)
	{
		fflush(stdout);

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
