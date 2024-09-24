/*
** EPITECH PROJECT, 2024
** vector
** File description:
** reverse
*/

#include "../include/my_vector.h"

void vector_reverse_function(vector *this)
{
    vector_node *current = this->head;
    vector_node *next_node = NULL;
    vector_node *temp = NULL;

    while (current != NULL) {
        this->head = current;
        next_node = current->next;
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = next_node;
    }
}


