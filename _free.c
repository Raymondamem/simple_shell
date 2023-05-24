#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void free_multiple(int count, ...)
{
    int i;
    va_list args;

    va_start(args, count);
    for (i = 0; i < count; i++)
    {
        void *ptr = va_arg(args, void *);
        free(ptr);
    }

    va_end(args);
}
