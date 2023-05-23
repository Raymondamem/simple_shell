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
	char *token;
	char *str;
	int str_len = 0;
	int path_len = 0;
	int file_len = _strlen(program);

	token = strtok(path, ":");
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
		if (str_len < (path_len + file_len))
		{
			str_len = path_len + file_len;
			str = realloc(str, (str_len * sizeof(char)) + 1);
		}
		_strcpy(str, token);
		if (str[(_strlen(str) - 1)] != '/')
		{
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
	free(str);
	return (NULL);
}
