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
	size_t len = _strlen(variable);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], variable, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

