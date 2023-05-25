#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *_strtok(char *str, const char *delim)
{
    static char *next_token;
    if (str != NULL)
        next_token = str;

    if (next_token == NULL)
        return NULL;

    char *current_token = next_token;
    while (*next_token != '\0')
    {
        if (strchr(delim, *next_token) != NULL)
        {
            *next_token = '\0';
            next_token++;
            return current_token;
        }
        next_token++;
    }

    next_token = NULL;
    return current_token;
}

