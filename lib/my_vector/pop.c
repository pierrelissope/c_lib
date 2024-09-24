/*
** EPITECH PROJECT, 2024
** vector
** File description:
** pop_back
*/

#include "../include/my_vector.h"

void *pop_function(vector *this, size_t index)
{
    vector_node *current_node = this->head;
    vector_node *temp = NULL;
    void *data = NULL;

    --(this->length);
    if (index == 0 && this->length > 0) {
        temp = this->head;
        this->head = temp->next;
        this->head->prev = temp->prev;
        data = temp->data;
        my_free(temp, this->tracker);
    } else if (index > 0 && index < this->length) {
        for (size_t i = 0; i < index; ++i) {
            temp = current_node;
            current_node = current_node->next;
        }
        temp->next = current_node->next;
        current_node->next->prev = temp;
        data = current_node->data;
        my_free(current_node, this->tracker);
    }
    return data;
}

void *pop_back_function(vector *this)
{
    return pop_function(this, this->length - 1);
}
