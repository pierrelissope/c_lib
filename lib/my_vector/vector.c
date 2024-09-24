/*
** EPITECH PROJECT, 2024
** vector
** File description:
** vector
*/

#include "../include/my_vector.h"
#include "../include/my_stdlib.h"

vector *newVector(alloc_tracker *tracker)
{
    vector *this = my_calloc(1, sizeof(vector), tracker);

    if (this == NULL)
        return NULL;
    this->tracker = tracker;
    this->begin = vector_begin_function;
    this->end = vector_end_function;
    this->push_back = push_back_function;
    this->pop_back = pop_back_function;
    this->clear = clear_function;
    this->pop = pop_function;
    this->find = vector_find_function;
    this->at = vector_at_function;
    this->set = vector_set_function;
    this->front = vector_front_function;
    this->back = vector_back_function;
    return this;
}

void clear_function(vector *this)
{
    vector_node *current_node = this->head;
    vector_node *temp = NULL;

    while (current_node != NULL) {
        temp = current_node;
        current_node = current_node->next;
        my_free(temp, this->tracker);
    }
    this->head = NULL;
    this->length = 0;
}

