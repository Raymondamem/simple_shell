#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * get_new_size - calculates the new size for the buffer
 * @old_size: the old size of the buffer
 * Return: the new size of the buffer
 */
size_t get_new_size(size_t old_size)
{
	size_t new_size;

	new_size = old_size + (old_size >> 2);
	if (new_size < 120)
	{
		new_size = 120;
	}

	return (new_size);
}

/**
 * realloc_buffer - reallocates the buffer to a new size
 * @buffer: the old buffer
 * @new_size: the new size of the buffer
 * Return: a pointer to the newly allocated buffer or NULL on failure
 */
char *realloc_buffer(char *buffer, size_t new_size)
{
	char *new_ptr;

	new_ptr = realloc(buffer, new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	return (new_ptr);
}

/**
 * _getline - gets line from std
 * @lineptr: ptr to line str
 * @n: n val
 * @stream: ptr to file stream
 * Return: retuns str
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos;
	char c;
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
			return (-1);
	}
	pos = 0;
	while (fread(&c, sizeof(char), 1, stream) == 1)
	{
		if (pos + 1 >= *n)
		{
			new_size = get_new_size(*n);
			new_ptr = realloc_buffer(*lineptr, new_size);
			if (new_ptr == NULL)
			{
				return (-1);
			}
			*n = new_size;
			*lineptr = new_ptr;
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
			break;
	}
	(*lineptr)[pos] = '\0';
	return (pos > 0 ? (ssize_t)pos : -1);
}
