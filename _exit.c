#include "main.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/**
 * print_exit_error - prints error message for exit command
 * @shell_data: shell data information
 * @code: program exit code
 * Return: void
*/
void print_exit_error(info_t *shell_data, char *code)
{
	dprintf(STDERR_FILENO, "%s: 1: exit: Illegal number: %s\n",
	shell_data->shell_name, code);
}

/**
 * __exit - exit from shell
 * @shell_data: shell data
 * Return: void
*/
void __exit(info_t *shell_data)
{
	char *token;
	char *string_copy = NULL;
	int exit_code = shell_data->exit_code;

	string_copy = _strdup(shell_data->line);
	token = _strtok(string_copy, " ");
	token = _strtok(NULL, " ");
	if (token != NULL)
	{
		exit_code = _atoi(token);
		if (is_valid_number(token) == 0)
		{
			print_exit_error(shell_data, token);
			free_multiple(1, string_copy);
			if (shell_data->interactive == 1)
				return;
			free_multiple(1, shell_data->line);
			exit(2);
		}
		if (exit_code < 0)
		{
			print_exit_error(shell_data, token);
			free_multiple(2, shell_data->line, string_copy);
			exit(2);
		}
	}
	free_multiple(2, shell_data->line, string_copy);
	exit(exit_code);
}
