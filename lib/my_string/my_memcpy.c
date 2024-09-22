#include "../include/my_string.h"
#include <stdio.h>

void *my_memcpy(void *dest, void *src, size_t size)
{
    char *source = src;
    char *destination = dest;

    if (src == NULL || dest == NULL || size == 0)
        return NULL;
    for (size_t i = 0; i < size; ++i) {
        char cs = source[i];
        destination[i] = cs;
    }
    return dest;
}

void *my_memset(void *dest, int c, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        ((char *)dest)[i] = c;
    }
    return dest;
}

