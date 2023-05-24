#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * run_cmd - runs command
 * @command: command to run
 * @shell_name: shell name
 *
 * Return: void
 */
void run_cmd(char *command, char *shell_name)
{
	char *full_path = NULL;
	char **argv = NULL;
	pid_t id;

	argv = get_argv(command);
	full_path = get_exec_path(argv[0]);
	if (full_path == NULL)
	{
		perror("File not found");
		free_array((void **)argv, sizeof(argv) / sizeof(char));
		free_multiple(1, full_path);
		prompt();
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

