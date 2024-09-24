/*
** EPITECH PROJECT, 2024
** strcat
** File description:
** strcat
*/

#include "../include/my_string.h"

char *my_strcat(char *dest, char const *src)
{
    size_t len_dest = my_strlen(dest);
    size_t len_src = my_strlen(src);

    my_memcpy(dest + len_dest, src, len_src);
    dest[len_dest + len_src] = '\0';
    return dest;
}

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    int lenS1 = my_strlen(s1);

    for (int i = 0; i <= lenS1; i++) {
        if (s1[i] == s2[i]) {
            result = 0;
        }
        if (s1[i] < s2[i]) {
            return (s1[i] - s2[i]);
        }
        if (s1[i] > s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    result = 0;
    return result;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;

    if (!s1 || !s2)
        return 84;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            result = 0;
        }
        if (s1[i] < s2[i]) {
            return (s1[i] - s2[i]);
        }
        if (s1[i] > s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    result = 0;
    return result;
}

char *my_strstr(char *fullstring, char *substring)
{
    int lensub = my_strlen(substring);

    while (*fullstring) {
        if (*fullstring == *substring &&
            my_strncmp(fullstring, substring, lensub) == 0) {
            return fullstring;
        }
        fullstring++;
    }
    return NULL;
}

char *my_strchr(char *str, int c)
{
    while (*str != c && *str != '\0')
        str++;
    return str;
}
