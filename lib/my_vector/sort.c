/*
** EPITECH PROJECT, 2024
** sort
** File description:
** vector sort
*/

#include "../include/my_vector.h"

static vector_node *merge(vector_node *left, vector_node *right,
    int (*cmp)(void const *data1, void const *data2))
{
    vector_node *new_head = NULL;
    vector_node *next_node = NULL;

    if (left == NULL) {
        right->prev = NULL;
        return right;
    }
    if (right == NULL) {
        left->prev = NULL;
        return left;
    }
    if (cmp(left->data, right->data) < 0) {
        new_head = left;
        new_head->prev = NULL;
        left = left->next;
        next_node = merge(left, right, cmp);
        next_node->prev = new_head;
        new_head->next = next_node;
    } else {
        new_head = right;
        new_head->prev = NULL;
        right = right->next;
        next_node = merge(left, right, cmp);
        next_node->prev = new_head;
        new_head->next = next_node;
    }
    return new_head;
}

static vector_node *split(vector_node *head)
{
    vector_node *slow = head;
    vector_node *fast = head;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    slow->prev->next = NULL;
    return slow;
}

static vector_node *merge_sort(vector_node *head,
    int (*cmp)(void const *data1, void const *data2))
{
    if (head->next == NULL)
        return head;

    vector_node *left = head;
    vector_node *right = split(head);

    left = merge_sort(left, cmp);
    right = merge_sort(right, cmp);

    return merge(left, right, cmp);
}

void vector_sort_function(vector *this,
    int (*cmp)(void const *data1, void const *data2))
{
    this->head = merge_sort(this->head, cmp);
}
