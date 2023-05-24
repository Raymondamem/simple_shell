#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _env - print all environment variables
 * @command: command to execute
 * @shell_name: name of the shell
 * Return: void
*/
void _env(char *command, char *shell_name)
{
	UNUSED(command);
	UNUSED(shell_name);
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
