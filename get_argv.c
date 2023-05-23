#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * get_argv - sets argument vector for program
 * @argc: number of argument
 * @argv: array of argument
 * Return: void
*/
char **get_argv(char *line)
{
	char **argv = NULL;
	int argc = 0;
	int arr_size = 10;
	char *token;
	char *str_copy;
	int i;

	str_copy = strdup(line);
	if (str_copy == NULL)
	{
		exit(EXIT_FAILURE);
	}
	argv = malloc(arr_size * sizeof(char *));
	if (argv == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(str_copy, " ");
	while (token != NULL)
	{
		if (argc >= arr_size)
		{
			arr_size *= 2;
			argv = realloc(argv, arr_size * sizeof(char *));
			if (argv == NULL)
			{
				for (i = 0; i < argc; i++)
				{
					free(argv[i]);
				}
				free(str_copy);
				free(argv);
				exit(EXIT_FAILURE);
			}
		}
		argv[argc] = strdup(token);
		if (argv[argc] == NULL)
		{
			for (i = 0; i < argc; i++)
			{
				free(argv[i]);
			}
			free(str_copy);
			free(argv);
			exit(EXIT_FAILURE);
		}
		argc++;
		token = strtok(NULL, " ");
	}
	if (argc >= arr_size)
	{
		arr_size++;
		argv = realloc(argv, arr_size * sizeof(char *));
		if (argv == NULL)
		{
			for (i = 0; i < argc; i++)
			{
				free(argv[i]);
			}
			free(str_copy);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	argv[argc] = NULL;
	free(str_copy);
	return (argv);
}