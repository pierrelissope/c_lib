/*
** EPITECH PROJECT, 2024
** iterator
** File description:
** iterator
*/

#include "../include/my_vector.h"

vector_iterator vector_begin_function(vector *this)
{
    return this->head;
}

vector_iterator vector_end_function(vector *this)
{
    (void)this;
    return NULL;
}

