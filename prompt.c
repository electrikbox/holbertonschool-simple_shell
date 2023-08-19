#include "main.h"

char* trim_input(char* input)
{
    char* trimmed_input = input;

    while (*trimmed_input == ' ' || *trimmed_input == '\t')
        trimmed_input++;

    if (*trimmed_input == '\n' || *trimmed_input == '\0')
        return NULL;

    return trimmed_input;
}

/**
 * main - Shell
 * @ac: Number of arguments
 * @av: Arguments
 * Return: 0
*/
int main(void)
{
	int exeCmd;
	char *input = NULL, *trimmed_input = NULL;
	size_t bufsize = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
            printf("ⓢ ");

		read = getline(&input, &bufsize, stdin);
        if (read == -1)
            break;

        trimmed_input = trim_input(input);
        if (trimmed_input == NULL)
            continue;

		exeCmd = execute(input);
		if (exeCmd == -1)
			perror("error");
	}

	free(input);
	return (0);
}
