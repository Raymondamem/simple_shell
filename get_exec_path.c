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
	char *copy_path = NULL;
	char *token;
	char fullpath[PATH_MAX];

	if (path == NULL)
		return (NULL);
	copy_path = _strdup(path);
	token = _strtok(copy_path, ":");
	while (token != NULL)
	{
		_strcpy(fullpath, token);
		if (fullpath[_strlen(fullpath) - 1] != '/')
		{
			strcat(fullpath, "/");
		}
		_strcat(fullpath, program);
		if (access(fullpath, F_OK) == 0)
		{
			free_multiple(1, copy_path);
			return (_strdup(fullpath));
		}
		token = _strtok(NULL, ":");
	}
	free_multiple(1, copy_path);
	if (access(program, F_OK) == 0)
		return (_strdup(program));
	return (NULL);
}
