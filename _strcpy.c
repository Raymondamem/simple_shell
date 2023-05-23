#include "main.h"

char *_strcpy(char *dest, char *src)
{
    char *temp = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return temp;
}
