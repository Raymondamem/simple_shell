#include "main.h"
#include <string.h>

/**
 * _strcspn - calculates length of initial segment
 * of string that consists of characters not in set.
 * @str: the string
 * @reject: what not to count
 * Return: returns number of reject
 */
size_t _strcspn(const char *str, const char *reject)
{
	size_t count = 0;

	while (*str)
	{
		for (const char *r = reject; *r; r++)
		{
			if (*str == *r)
			{
				return (count);
			}
		}
		count++;
		str++;
	}
	return (count);
}
