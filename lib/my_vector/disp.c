/*
** EPITECH PROJECT, 2024
** vector
** File description:
** disp
*/

#include "../include/my_vector.h"
#include "../include/my_stdio.h"

void vector_disp_function(vector *this, char *separator, void (*func)(void *))
{
    for (vector_iterator it = this->begin(this);
        it != this->end(this); it = it->next) {
        func(it->data);
        if (it->next != this->end(this))
            my_putstr(separator);
    }
}
