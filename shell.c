#include "main.h"


int main(int argc, char **argv)
{
	char *linePtr = NULL, *linePtrCopy = NULL, *token;
	size_t number = 0;
	ssize_t lengthLinePtr;
	const char *delim = " \n";
	int tokensNumber = 0, index;

	(void)argc;

	while (1)
	{
		lengthLinePtr = getline(&linePtr, &number, stdin);

		if (lengthLinePtr == -1)
		{
			free(linePtr);
			return (-1);
		}

		if (*linePtr == '\n')
			continue;

		linePtrCopy = malloc(sizeof(char) * lengthLinePtr + 1);

		if (linePtrCopy == NULL)
		{
			perror(argv[0]);
			free(linePtr);
			free(linePtrCopy);
			return (-1);
		}

		strcpy(linePtrCopy, linePtr);

		token = strtok(linePtr, delim);

		while (token != NULL)
		{
			tokensNumber++;
			token = strtok(NULL, delim);
		}
		tokensNumber++;

		argv = malloc(sizeof(char *) * tokensNumber + 1);

		token = strtok(linePtrCopy, delim);

		for (index = 0; token != NULL; index++)
		{
			argv[index] = malloc(sizeof(char) * strlen(token) + 1);
			strcpy(argv[index], token);
			token = strtok(NULL, delim);
		}

		argv[index] = NULL;
		execmd(argv);

		for (index = 0; argv[index] != NULL; index++)
			free(argv[index]);
		free(argv);

		free(linePtrCopy);
	}
	free(linePtr);
	return (0);
}
