/*
** EPITECH PROJECT, 2024
** iterator
** File description:
** iterator
*/

#include "../include/my_vector.h"
#include <stdio.h>

vector_iterator vector_begin_function(vector *this)
{
    return this->head;
}

vector_iterator vector_end_function(vector *this)
{
    vector_iterator it = this->head;

    while (it != NULL)
        it = it->next;
    return it;
}

