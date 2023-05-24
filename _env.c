#include "main.h"
#include <stdlib.h>
#include <unistd.h>

void _env(__attribute__((unused))char *command, __attribute__((unused))char *shell_name)
{
    int i = 0;

    while (environ[i] != NULL)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
