#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @d: pointer to store string in memory
 * Return : returns address to string
 */
char *_strdup(const char *s) {
    char *d = malloc(_strlen(s) + 1);   // Allocate memory

    if (d != NULL)
    {
	    _strcpy(d,s);         // Copy string if okay
    }
    return d;                           // Return new memory
}
