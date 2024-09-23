/*
** EPITECH PROJECT, 2024
** alloc
** File description:
** allocator
*/

#include "../include/my_stdlib.h"
#include <stdio.h>
#include <string.h>

void *my_malloc(size_t size, alloc_tracker *tracker)
{
    void *ptr = malloc(size + CHUNK_METADATA_SIZE);

    if (ptr == NULL)
        return NULL;
    ((chunk_metadata *)ptr)->size = size;
    ((chunk_metadata *)ptr)->next = NULL;
    tracker_add(tracker, ptr);
    return (char *)ptr + CHUNK_METADATA_SIZE;
}

void *my_calloc(size_t nmemb, size_t size, alloc_tracker *tracker)
{
    void *ptr = my_malloc(size * nmemb, tracker);

    if (ptr == NULL)
        return NULL;
    memset(ptr, 0, size * nmemb);
    return ptr;
}

void *my_realloc(void *ptr, size_t size, alloc_tracker *tracker)
{
    void *new_ptr = NULL;
    size_t old_size = 0;

    if (size <= 0)
        return NULL;
    if (ptr == NULL)
        return my_malloc(size, tracker);
    new_ptr = my_malloc(size, tracker);
    old_size = ((chunk_metadata *)ptr - 1)->size;
    if (new_ptr == NULL)
        return NULL;
    memcpy(new_ptr, ptr, old_size <= size ? old_size : size);
    my_free(ptr, tracker);
    return new_ptr;
}
