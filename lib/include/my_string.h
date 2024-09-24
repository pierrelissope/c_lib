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
char *my_strndup(char const *str, size_t n, alloc_tracker *tracker);
void *my_memset(void *dest, int c, size_t size);
void *my_memcpy(void *dest, void const *src, size_t size);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *fullstring, char *substring);
char *my_strchr(char *str, int c);
string *new_string(const char *content, alloc_tracker *tracker);
