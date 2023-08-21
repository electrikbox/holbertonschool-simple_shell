#include "main.h"

/**
 * trimInput - Trim of input
 * @input: input to trim
 * Return: Trimmed input
*/

char *trimInput(char *input)
{
	char *trimmedInput = input;

	while (*trimmedInput == ' ' || *trimmedInput == '\t')
		trimmedInput++;

	if (*trimmedInput == '\n' || *trimmedInput == '\0')
		return (NULL);

	return (trimmedInput);
}
