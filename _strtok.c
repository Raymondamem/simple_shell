#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * _strtok - tokenizes a sentence
 * @str: sentence to tokenize
 * @delim: char to use for it
 * Return: returns string of each token
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *current_token;

	if (str != NULL)
		next_token = str;

	if (next_token == NULL)
		return (NULL);

	current_token = next_token;
	while (*next_token != '\0')
	{
		if (strchr(delim, *next_token) != NULL)
		{
			*next_token = '\0';
			next_token++;
			return (current_token);
		}
		next_token++;
	}

	next_token = NULL;
	return (current_token);
}

