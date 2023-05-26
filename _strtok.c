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

	if (str)
		next_token = str;

	if (!next_token)
		return (NULL);

	str = next_token + _strspn(next_token, delim);
	next_token = str + _strcspn(str, delim);
	if (*next_token)
	{
		*next_token++ = '\0';
	}
	else
	{
		next_token = NULL;
	}
	return (*str ? str : NULL);
}

