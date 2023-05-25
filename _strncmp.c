#include "main.h"
#include <stdio.h>

/**
 * _strncmp - get difference of s1 && s2
 * @s1: string one
 * @s2:  string two
 * @n: number of char to compe.. up to
 * Return: returns difference btw s1 && s2 if eny else (0)
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	if (i == n)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

