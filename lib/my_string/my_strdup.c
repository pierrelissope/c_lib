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
    char *ptr = my_malloc(length, tracker);

    if (ptr == NULL)
        return NULL;
    my_memcpy(ptr, str, length + 1);
    return ptr;
}
