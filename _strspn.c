#include "main.c"
#include <string.h>

/**
 * _strspn - calculates length of initial segment of string that consists of characters in set
 * @str: the string
 * @accept: what to count in str
 * Return: retuns number of accept in str
 */
size_t _strspn(const char *str, const char *accept)
{
	size_t count = 0;

	while (*str)
	{
		bool found = false;
		for (const char *a = accept; *a; a++)
		{
			if (*str == *a)
			{
				found = true;
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

