/*
** EPITECH PROJECT, 2024
** vector
** File description:
** get_array
*/

#include "../include/my_vector.h"

void **vector_get_array_function(vector *this, alloc_tracker *tracker)
{
    void **array = my_calloc(this->length + 1, sizeof(void *), tracker);
    size_t i = 0;

    if (array == NULL)
        return NULL;
    for (vector_iterator it = this->begin(this);
        it != this->end(this); it = it->next) {
        array[i] = it->data;
    }
    return array;
}

