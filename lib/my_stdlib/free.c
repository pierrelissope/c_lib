/*
** EPITECH PROJECT, 2024
** free
** File description:
** free
*/

#include "../include/my_stdlib.h"

void my_free(void *ptr, alloc_tracker *tracker)
{
    if (ptr == NULL)
        return;
    tracker_remove(tracker, (void *)((char *)ptr - CHUNK_METADATA_SIZE));
    free((char *)ptr - CHUNK_METADATA_SIZE);
}

