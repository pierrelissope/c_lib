/*
** EPITECH PROJECT, 2024
** vector header
** File description:
** header
*/

#pragma once

#include "my_stdlib.h"

typedef struct vector_node_s {
    void *data;
    struct vector_node_s *next;
} vector_node;

typedef vector_node * vector_iterator;

typedef struct vector_s {
    size_t length;
    vector_node *head;
    alloc_tracker *tracker;

    vector_iterator (*begin)(struct vector_s *);
    vector_iterator (*end)(struct vector_s *);

    void (*push_back)(struct vector_s *, void *);
    void *(*pop_back)(struct vector_s *);
    void (*clear)(struct vector_s *);
    void *(*pop)(struct vector_s *, size_t);
} vector;

vector *newVector(alloc_tracker *tracker);

vector_iterator vector_begin_function(vector *this);
vector_iterator vector_end_function(vector *this);

void push_back_function(vector *this, void *data);
void *pop_back_function(vector *this);
void clear_function(vector *this);
void *pop_function(vector *this, size_t index);

