#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int free_multiple(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        void *ptr = va_arg(args, void *);
        free(ptr);
    }

    va_end(args);
}
