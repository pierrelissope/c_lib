/*
** EPITECH PROJECT, 2024
** header
** File description:
** header
*/

#pragma once

#include "../include/my_stdlib.h"

typedef struct {
    size_t length;
    char *buffer;
} string;

size_t my_strlen(char const *str);
char *my_strdup(char const *str, alloc_tracker *tracker);
char *my_strcpy(char *dest, char const *src);

void *my_memset(void *dest, int c, size_t size);
void *my_memcpy(void *dest, void const *src, size_t size);

string *new_string(const char *content, alloc_tracker *tracker);
