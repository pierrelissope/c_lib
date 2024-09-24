/*
** EPITECH PROJECT, 2024
** vector
** File description:
** push back
*/

#include "../include/my_vector.h"

static void vector_initialize_new_node(vector_node *current_node,
    vector_node *new_node)
{
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;
}

void push_back_function(vector *this, void *data)
{
    vector_node *current_node = this->head;
    vector_node *new_node = NULL;

    if (current_node == NULL) {
        this->head = my_calloc(1, sizeof(vector_node), this->tracker);
        if (this->head == NULL)
            return;
        this->length = 1;
        this->head->data = data;
        return;
    }
    new_node = my_calloc(1, sizeof(vector_node), this->tracker);
    if (new_node == NULL)
        return;
    ++(this->length);
    new_node->data = data;
    vector_initialize_new_node(current_node, new_node);
}
