#include "main.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

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
			free_multiple(1, string_copy);
			errno = EINVAL;
			perror(shell_data->shell_name);
			if (shell_data->interactive == 1)
				return;
			free_multiple(1, shell_data->line);
			exit(2);
		}
		if (exit_code < 0)
		{
			errno = EINVAL;
			perror(shell_data->shell_name);
		}
	}
	free_multiple(2, shell_data->line, string_copy);
	exit(exit_code);
}
