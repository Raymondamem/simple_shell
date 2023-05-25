#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * _exec - execute a program
 * @command: command to execute
 * @shell_name: name of the shell
 * Return: void
*/
void _exec(char *command, char *shell_name)
{
	char *full_path = NULL;
	char **argv = NULL;
	pid_t id;

	argv = get_argv(command);
	if (argv[0][0] != '/' && argv[0][0] != '.')
		full_path = get_exec_path(argv[0]);
	else
		full_path = _strdup(argv[0]);
	if (full_path == NULL)
	{
		perror(shell_name);
		free_array((void **)argv, sizeof(argv) / sizeof(char));
	}
	else
	{
		id = _fork();
		if (id == 0)
		{
			if (execve(full_path, argv, NULL) == -1)
			{
				perror(shell_name);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		free_array((void **)argv, sizeof(argv) / sizeof(char));
		free_multiple(1, full_path);
	}
}
