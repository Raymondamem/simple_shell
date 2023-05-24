#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - duplicates a string
 * @d : pointer to store string in memory
 * return : returns address to string
 */
char *_strdup(const char *s) {
    char *d = malloc(strlen(s) + 1);   // Allocate memory

    if (d != NULL)
    {
	    strcpy(d,s);         // Copy string if okay
    }

    return d;                           // Return new memory
}
