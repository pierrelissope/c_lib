/*
** EPITECH PROJECT, 2024
** string
** File description:
** string management
*/

#include "../include/my_string.h"
#include "../include/my_stdlib.h"

string *new_string(char const *content, alloc_tracker *tracker)
{
    size_t length = my_strlen(content);
    string *obj = my_calloc(length, 1, tracker);

    if (obj == NULL)
        return NULL;
    obj->length = length;
    obj->buffer = my_strdup(content, tracker);
    if (obj->buffer == NULL) {
        my_free(obj, tracker);
        return NULL;
    }
    return obj;
}
