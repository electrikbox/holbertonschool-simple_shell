#include "main.h"

/**
 * tokenize - tokenizes a string
 * @input: string to tokenize
 * Return: array of tokens
*/
char **tokenize(char *input)
{
	char *token;
	char **args = NULL;
	int argCount = 0;

	args = calloc(10, sizeof(char *));

	if (args == NULL)
		return (NULL);

	token = strtok(input, " \t\n");

	if (!token)
	{
		free(args);
		return (NULL);
	}

	while (token != NULL)
	{
		args[argCount++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;

	return (args);
}
