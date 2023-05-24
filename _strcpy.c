#include "main.h"

/**
 * _strcpy - copies src to deat
 * @dest: destination of string
 * @src: source of string
 *
 * Return: returns pointer to the dest.
 */
char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (temp);
}
