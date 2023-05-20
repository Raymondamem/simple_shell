#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * _getenv - get an environmental variable
 * @variable: variable to find
 * Return: variable if found, else NULL
*/
char *_getenv(char *variable)
{
	int i = 0;
	char *token;

	token = strtok(environ[i], "=");
	while (environ[i] != NULL)
	{
		if (token != NULL)
		{
			if (_strcmp(token, variable) == 0)
			{
				token = strtok(NULL, "=");
				return (token);
			}
		}
		i++;
		token = strtok(environ[i], "=");
	}

	return (NULL);
}
