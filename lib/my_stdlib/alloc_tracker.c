#include "../include/my_stdlib.h"

alloc_tracker new_tracker(void)
{
    return (alloc_tracker){0};
}

void tracker_add(alloc_tracker *tracker, chunk_metadata *data)
{
    chunk_metadata *current = tracker->used;

    if (current == NULL) {
        tracker->used = data;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = data;
}

void tracker_remove(alloc_tracker *tracker, chunk_metadata *data)
{
    chunk_metadata *prev = NULL;
    chunk_metadata *current = tracker->used;
    
    while (current != data) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        tracker->used = current->next;
    } else {
        prev->next = current->next;
    }
}

void my_free_all(alloc_tracker *tracker)
{
    chunk_metadata *current = tracker->used;
    chunk_metadata *temp = NULL;

    if (current == NULL)
        return;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    tracker->used = NULL;
}

