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
 * invalid_argv - checks if an argument is invalid
 * @argv: the arguments to check
 * @shell_data: the shell data
 * Return: -1 if the argument is invalid
 * and 0 otherwise
*/
int invalid_argv(char **argv, info_t *shell_data)
{
	if (argv[0] == NULL || argv[0][0] == '\0')
	{
		free_array((void **)argv, count_array_size(argv));
		if (shell_data->interactive == 0)
		{
			free_multiple(1, shell_data->line);
			exit(EXIT_SUCCESS);
		}
		else
			return (-1);
	}
	else
		return (0);
}

/**
 * hangle_path_null - checks if the path is invalid
 * @full_path: path to check
 * @argv: list of arguments
 * @shell_data: the shell data
 * Return: void
*/
void hangle_path_null(char *full_path, char **argv, info_t *shell_data)
{
	free_array((void **)argv, count_array_size(argv));
	if (shell_data->interactive == 0)
	{
		perror(shell_data->shell_name);
		free_multiple(2, full_path, shell_data->line);
		exit(127);
	}
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
	if (invalid_argv(argv, shell_data) == -1)
		return;
	else if (argv[0][0] != '/' && argv[0][0] != '.')
		full_path = get_exec_path(argv[0]);
	else
		full_path = _strdup(argv[0]);
	if (full_path == NULL)
		hangle_path_null(full_path, argv, shell_data);
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
