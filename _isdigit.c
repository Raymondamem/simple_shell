#include "main.h"

/**
 * _isdigit - checks if a number is a digit
 * @c: number to check
 * Return: 1 if digit, else 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}

/**
 * is_valid_number - checks if a number is a valid number
 * @str: string to check
 * Return: 1 if valid, else 0
*/
int is_valid_number(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (!_isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
