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
	char *copy_path = strdup(path);
	char *token, *str = NULL;
	int str_len = 0;
	int path_len = 0, file_len = _strlen(program);

	token = strtok(copy_path, ":");
	if (token != NULL)
	{
		path_len = _strlen(token);
		str_len = path_len + file_len;
		str = _malloc(str_len * sizeof(char) + 1);
	}
	while (token != NULL)
	{
		if ((path_len + file_len) >= str_len)
		{
			str_len = path_len + file_len;
			str = _realloc(str, (str_len * sizeof(char)) + 1);
		}
		_strcpy(str, token);
		str_len = _strlen(str);
		if (str[(str_len - 1)] != '/')
		{
			if ((path_len + file_len + 1) >= str_len)
				str = _realloc(str, (str_len * sizeof(char)) + 2);
			_strcat(str, "/");
		}
		_strcat(str, program);
		if (access(str, F_OK) == 0)
		{
			free_multiple(1, copy_path);
			return (str);
		}
		token = strtok(NULL, ":");
		if (token != NULL)
			path_len = _strlen(token);
	}
	free_multiple(2, str, copy_path);
	return (NULL);
}
