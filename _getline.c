#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/** _getline - gets line from std...
 * @lineptr: ptr to line str
 * @n: n val
 * @stream: ptr to file stream
 * Return retuns str
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos;
	int c;
	size_t new_size;
	char *new_ptr;

	if (!lineptr || !n || !stream)
	{
		errno = EINVAL;
		return (-1);
	}

	if (*lineptr == NULL || *n == 0)
	{
		*n = 120;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	pos = 0;
	c = fgetc(stream);
	while (c != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_size = *n + (*n >> 2);
			if (new_size < 120)
			{
				new_size = 120;
			}
			new_ptr = realloc(*lineptr, new_size);
			if (new_ptr == NULL)
			{
				return (-1);
			}
			*n = new_size;
			*lineptr = new_ptr;
		}

		(*lineptr)[pos++] = c;
		if (c == '\n')
		{
			break;
		}
		c = fgetc(stream);
	}

	(*lineptr)[pos] = '\0';
	return (pos > 0 ? (ssize_t)pos : -1);
}

