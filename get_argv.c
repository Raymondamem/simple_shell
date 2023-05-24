#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * realloc_array - reallocates an array memory
 * @ptr: array to reallocate
 * @array_size: size of the array
 * @argc: for freeing array
 * @str_copy: string to free if failed
 * Return: pointer to reallocates memory
*/
void **realloc_array(void **ptr, int *array_size, int *argc, char *str_copy)
{
	(*array_size) *= 2;
	ptr = realloc(ptr, (*array_size) * sizeof(char *));
	if (ptr == NULL)
	{
		free_array(ptr, *argc);
		free_multiple(1, str_copy);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * get_argv - sets argument vector for program
 * @line: string containing argument
 * Return: array containing string of argument
*/
char **get_argv(char *line)
{
	char **argv = NULL;
	int argc = 0, arr_size = 10;
	char *token, *str_copy;

	str_copy = strdup(line);
	argv = _malloc(arr_size * sizeof(char *));
	token = strtok(str_copy, " ");
	while (token != NULL)
	{
		if (argc >= arr_size)
			argv = (char **)realloc_array((void **)argv, &arr_size, &argc, str_copy);
		argv[argc] = strdup(token);
		if (argv[argc] == NULL)
		{
			free_array((void **)argv, argc);
			free_multiple(1, str_copy);
			exit(EXIT_FAILURE);
		}
		argc++;
		token = strtok(NULL, " ");
	}
	if (argc >= arr_size)
		argv = (char **)realloc_array((void **)argv, &arr_size, &argc, str_copy);
	argv[argc] = NULL;
	free_multiple(1, str_copy);
	return (argv);
}
