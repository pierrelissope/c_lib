/*
** EPITECH PROJECT, 2024
** header
** File description:
** header
*/

#pragma once

#include <stdint.h>
#include <stdlib.h>

#define CHUNK_METADATA_SIZE sizeof(chunk_metadata)

typedef struct chunk_metadata_s {
    size_t size;
    struct chunk_metadata_s *next;
} chunk_metadata;

typedef struct {
    void *stack_bottom;
    chunk_metadata *used;
} alloc_tracker;

void *my_malloc(size_t size, alloc_tracker *tracker);
void *my_realloc(void *ptr, size_t size, alloc_tracker *tracker);
void *my_calloc(size_t nmemb, size_t size, alloc_tracker *tracker);
void my_free(void *ptr, alloc_tracker *tracker);
void my_free_all(alloc_tracker *tracker);

alloc_tracker new_tracker(void);
void tracker_add(alloc_tracker *tracker, chunk_metadata *data);
void tracker_remove(alloc_tracker *tracker, chunk_metadata *data);
