/*
** EPITECH PROJECT, 2024
** strdup
** File description:
** dup char*
*/

#include "../include/my_stdlib.h"
#include "../include/my_string.h"

char *my_strdup(char const *str, alloc_tracker *tracker)
{
    size_t length = my_strlen(str);
    char *ptr = my_malloc(length + 1, tracker);

    if (ptr == NULL)
        return NULL;
    my_memcpy(ptr, str, length + 1);
    return ptr;
}

char *my_strndup(char const *str, size_t n, alloc_tracker *tracker)
{
    char *ptr = my_malloc(n + 1, tracker);

    if (ptr == NULL)
        return NULL;
    my_memcpy(ptr, str, n + 1);
    return ptr;
}

