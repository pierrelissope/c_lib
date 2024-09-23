/*
** EPITECH PROJECT, 2024
** strlen
** File description:
** get the length of a char *
*/

#include <string.h>

size_t my_strlen(char const *str)
{
    size_t length = 0;

    while (str[length])
        ++length;
    return length;
}
