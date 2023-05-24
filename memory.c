#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * free_multiple - free multiple memory
 * @count: number of memory to free
 * Return: Void
*/
void free_multiple(int count, ...)
{
	int i;
	void *ptr;
	va_list args;

	va_start(args, count);
	for (i = 0; i < count; i++)
	{
		ptr = va_arg(args, void *);
		free(ptr);
		ptr = NULL;
	}
	va_end(args);
}

/**
 * free_array - free multiple memory array
 * @array: array to free
 * @array_size: size of array to free
 * Return: Void
*/
void free_array(void **array, int array_size)
{
	int i;

	for (i = 0; i < array_size; i++)
	{
		free_multiple(1, array[i]);
	}
	free_multiple(1, array);
}

/**
 * _malloc - a wrapper for malloc
 * @size: size of memory to allocate
 * Return: pointer to allocated memory
*/
void *_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * _realloc - a wrapper for realloc
 * @ptr: pointer to the function to resize
 * @size: size of new memory size
 * Return: void
*/
void *_realloc(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);

	if (ptr == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
