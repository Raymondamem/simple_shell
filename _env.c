#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _env - print all environment variables
 * @shell_data: shell data
 * Return: void
*/
void _env(info_t *shell_data)
{
	int i = 0;

	UNUSED(shell_data);

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
