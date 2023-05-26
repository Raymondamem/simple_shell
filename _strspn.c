#include "main.h"

/**
 * _strspn - calculates length of initial segment
 * of string that consists of characters in set
 * @str: the string
 * @accept: what to count in str
 * Return: retuns number of accept in str
 */
size_t _strspn(const char *str, const char *accept)
{
	size_t count = 0;
	int found = 0;
	const char *a;

	while (*str)
	{
		found = 0;
		for (a = accept; *a; a++)
		{
			if (*str == *a)
			{
				found = 1;
				break;
			}
		}

		if (!found)
		{
			break;
		}

		count++;
		str++;
	}
	return (count);
}

