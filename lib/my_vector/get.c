/*
** EPITECH PROJECT, 2024
** vector
** File description:
** get
*/

#include "../include/my_vector.h"
#include <stdio.h>

size_t vector_find_function(vector *this, void *data)
{
    size_t index = 0;

    for (vector_iterator it = this->begin(this);
        it != this->end(this); it = it->next) {
        if (data == it->data)
            return index;
        ++index;
    }
    return -1;
}

void *vector_at_function(vector *this, size_t index)
{
    size_t i = 0;

    printf("you are asking for %zu\n", index);
    if (i >= this->length)
        return NULL;
    for (vector_iterator it = this->begin(this);
        it != this->end(this); it = it->next) {
        printf("at position %zu: there is : %s\n", i, (char *)it->data);
        if (i == index) {
            printf("I return it\n");
            return it->data;
        }
        ++i;
    }
    return NULL;
}

void vector_set_function(vector *this, size_t index, void *data)
{
    size_t i = 0;

    if (i >= this->length)
        return;
    for (vector_iterator it = this->begin(this);
        it != this->end(this); it = it->next) {
        if (i == index) {
            it->data = data;
            break;
        }
        ++i;
    }
}

void *vector_front_function(vector *this)
{
    if (this->head == NULL)
        return NULL;
    return this->head->data;
}

void *vector_back_function(vector *this)
{
    if (this->head == NULL)
        return NULL;
    return vector_at_function(this, this->length - 1);
}

