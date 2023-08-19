#include "main.h"


char *getEnv(const char *input)
{
    const char *filename, *pathEnv;
    char *pathCopy, *token, *fullPath, *result = NULL;
    size_t inputLen, fullPathLen;

    pathEnv = getenv("PATH");

    if (!pathEnv)
        return NULL;

    pathCopy = strdup(pathEnv);
    if (!pathCopy)
        return NULL;

    token = pathCopy;
    inputLen = strlen(input);

    while ((token = strchr(token, ':')) != NULL)
    {
        *token = '\0';
        filename = input;

        fullPathLen = strlen(pathCopy) + 1 + inputLen + 1;
        fullPath = (char *)malloc(fullPathLen);
        if (!fullPath)
        {
            free(pathCopy);
            return NULL;
        }
        snprintf(fullPath, fullPathLen, "%s/%s", pathCopy, filename);

        if (access(fullPath, F_OK | X_OK) == 0)
        {
            result = strdup(fullPath);
            free(fullPath);
            break;
        }

        free(fullPath);
        token++;
    }

    free(pathCopy);
    return result;
}
