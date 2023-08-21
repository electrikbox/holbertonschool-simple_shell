#include "main.h"

/**
 * getPathEnv - get the full path of an executable
 * @input: executable's name
 * Return: fullPath of the executable if success or NULL if failure
*/

char *getPathEnv(char *input)
{
	char *result, *pathEnv, *pathEnvCopy, *token, fullPath[1024];

	pathEnv = getenv("PATH");

	if (pathEnv == NULL)
		return (NULL);

	pathEnvCopy = strdup(pathEnv);

	token = strtok(pathEnvCopy, ":");

	while (token)
	{
		snprintf(fullPath, sizeof(fullPath), "%s/%s", token, input);

		if (access(fullPath, F_OK | X_OK) == 0)
		{
			result = strdup(fullPath);
			free(pathEnvCopy);
			return (result);
		}

		token = strtok(NULL, ":");
	}
	free(pathEnvCopy);

	return (NULL);

}
