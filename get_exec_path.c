#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_exec_path - get path
 * @program: program name to find the executable
 * Return: fullpath to executable on Success,
 * NULL on failure
*/
char *get_exec_path(char *program)
{
	char *path = _getenv("PATH");
	char *copy_path = malloc(_strlen(path) + 1);
	char *token;
	char *str = NULL;
	int str_len = 0;
	int path_len = 0;
	int file_len = _strlen(program);

	_strcpy(copy_path, path);
	token = strtok(copy_path, ":");
	if (token != NULL)
	{
		path_len = _strlen(token);
		str_len = path_len + file_len;
		str = malloc(str_len * sizeof(char) + 1);
		if (str == NULL)
			exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		if ((path_len + file_len) >= str_len)
		{
			str_len = path_len + file_len;
			str = realloc(str, (str_len * sizeof(char)) + 1);
		}
		_strcpy(str, token);
		str_len = _strlen(str);
		if (str[(str_len - 1)] != '/')
		{
			if ((path_len + file_len + 1) >= str_len)
				str = realloc(str, (str_len * sizeof(char)) + 2);
			_strcat(str, "/");
		}
		_strcat(str, program);
		if (access(str, F_OK) == 0)
			return (str);
		token = strtok(NULL, ":");
		if (token != NULL)
			path_len = _strlen(token);
	}
	if (str != NULL)
		free(str);
	if (copy_path != NULL)
		free(copy_path);
	return (NULL);
}
