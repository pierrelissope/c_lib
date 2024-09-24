/*
** EPITECH PROJECT, 2024
** vector header
** File description:
** header
*/

#pragma once

#include "my_stdlib.h"

// Base struct for the vector propreties
typedef struct vector_node_s {
    void *data;
    struct vector_node_s *next;
    struct vector_node_s *prev;
} vector_node;

typedef vector_node * vector_iterator;

typedef struct vector_s {
    // The length of the list
    size_t length;
    // The head of the list
    vector_node *head;
    // The custom alloc_tracker of the list
    alloc_tracker *tracker;

    // Get the iterator of the first element of the list
    vector_iterator (*begin)(struct vector_s *);
    // Get the iterator of the last element of the list
    vector_iterator (*end)(struct vector_s *);

    // Push item to the end of the list
    void (*push_back)(struct vector_s *, void *data);
    //Pop the last item of the list
    void *(*pop_back)(struct vector_s *);
    // Clear the list
    void (*clear)(struct vector_s *);
    // Pop an item with its index
    void *(*pop)(struct vector_s *, size_t index);

    // Find an item in the list
    size_t (*find)(struct vector_s *, void *data); // Get the item at the index
    void *(*at)(struct vector_s *, size_t index);
    // Set the item at the index
    void (*set)(struct vector_s *, size_t index, void *data);
    // Get the first item of the list
    void *(*front)(struct vector_s *);
    // Get the last item of the list
    void *(*back)(struct vector_s *);
    // Sort the list with a cmp function
    void (*sort)(struct vector_s *,
        int (*compare)(void const *data1, void const *data2));
    // Display the list with a separator
    void (*disp)(struct vector_s *, char *separator, void (*func)(void *));
    // Get array of the list
    void **(*get_array)(struct vector_s *, alloc_tracker *tracker);
    void (*reverse)(struct vector_s *);
} vector;

// Creating a new vector
vector *newVector(alloc_tracker *tracker);

// You are not going to use them.
vector_iterator vector_begin_function(vector *this);
vector_iterator vector_end_function(vector *this);
void push_back_function(vector *this, void *data);
void *pop_back_function(vector *this);
void clear_function(vector *this);
void *pop_function(vector *this, size_t index);
size_t vector_find_function(vector *this, void *data);
void *vector_at_function(vector *this, size_t index);
void vector_set_function(vector *this, size_t index, void *data);
void *vector_front_function(vector *this);
void *vector_back_function(vector *this);
void vector_sort_function(vector *,
    int (*cmp)(void const *data1, void const *data2));
void vector_disp_function(vector *, char *separator, void (*func)(void *));
void **vector_get_array_function(vector *, alloc_tracker *tracker);
void vector_reverse_function(vector *this);

