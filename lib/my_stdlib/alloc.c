#include "../include/my_stdlib.h"
#include "../include/my_string.h"
#include <stdio.h>
#include <string.h>

void *my_malloc(size_t size, alloc_tracker *tracker)
{
    void *ptr = malloc(size + CHUNK_METADATA_SIZE);

    ((chunk_metadata *)ptr)->size = size;
    ((chunk_metadata *)ptr)->next = NULL;
    tracker_add(tracker, ptr);
    return (char *)ptr + CHUNK_METADATA_SIZE;
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
    return new_ptr;
}
