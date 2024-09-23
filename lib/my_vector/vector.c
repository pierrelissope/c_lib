/*
** EPITECH PROJECT, 2024
** vector
** File description:
** vector
*/

#include "../include/my_vector.h"
#include "../include/my_stdlib.h"
#include <stdlib.h>
#include <strings.h>

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
    return this;
}

void push_back_function(vector *this, void *data)
{
    vector_node *current_node = this->head;
    vector_node *new_node = NULL;

    if (current_node == NULL) {
        this->head = my_calloc(1, sizeof(vector_node), this->tracker);
        if (this->head == NULL)
            return;
        this->head->data = data;
        return;
    }
    new_node = my_calloc(1, sizeof(vector_node), this->tracker);
    if (new_node == NULL)
        return;
    ++(this->length);
    new_node->data = data;
    while (current_node->next != NULL)
        current_node = current_node->next;
    current_node->next = new_node;
}

void *pop_back_function(vector *this)
{
    vector_node *current_node = this->head;
    vector_node *prev = NULL;
    void *data = NULL;

    if (current_node == NULL)
        return NULL;
    while (current_node->next != NULL) {
        prev = current_node;
        current_node = current_node->next;
    }
    --(this->length);
    if (prev == NULL) {
        this->head = NULL;
        return NULL;
    } else {
        prev->next = NULL;
        data = current_node->data;
        my_free(current_node, this->tracker);
        return data;
    }
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

void *pop_function(vector *this, size_t index)
{
    vector_node *current_node = this->head;
    vector_node *temp = NULL;
    void *data = NULL;

    if (index == 0 && this->length > 0) {
        temp = this->head;
        this->head = this->head->next;
        data = temp->data;
        my_free(temp, this->tracker);
    } else if (index > 0 && index < this->length) {
        for (size_t i = 0; i < index; ++i) {
            temp = current_node;
            current_node = current_node->next;
        }
        temp->next = current_node->next;
        data = current_node->data;
        my_free(current_node, this->tracker);
    }
    return data;
}

