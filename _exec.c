#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * count_array_size - count the size of an array
 * @arr: the array to count
 * Return: The size of the array
*/
int count_array_size(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		i++;
	}
	return (i);
}

/**
 * _exec - execute a program
 * @shell_data: shell data
 * Return: void
*/
void _exec(info_t *shell_data)
{
	char *full_path = NULL;
	char **argv = NULL;
	pid_t id;
	int wstatus;

	argv = get_argv(shell_data->line);
	if (argv[0] == NULL || argv[0][0] == '\0')
	{
		free_array((void **)argv, count_array_size(argv));
		if (shell_data->interactive == 0)
			free_multiple(1, shell_data->line);
		else
			return;
	}
	else if (argv[0][0] != '/' && argv[0][0] != '.')
		full_path = get_exec_path(argv[0]);
	else
		full_path = _strdup(argv[0]);
	if (full_path == NULL)
	{
		perror(shell_data->shell_name);
		free_array((void **)argv, count_array_size(argv));
	}
	else
	{
		id = _fork();
		if (id == 0)
		{
			if (execve(full_path, argv, environ) == -1)
			{
				perror(shell_data->shell_name);
				exit(EXIT_FAILURE);
			}
		}
		wait(&wstatus);
		free_array((void **)argv, count_array_size(argv));
		free_multiple(1, full_path);
		if (shell_data->interactive == 0)
		{
			if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
			{
				free_multiple(1, shell_data->line);
				exit(2);
			}
		}
	}
}
