/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "my_stdlib.h"
#include "my_vector.h"

int my_voidcmp(void const *d1, void const *d2)
{
    return strcmp(d1, d2);
}



int main(void)
{
    alloc_tracker tracker = new_tracker();
    vector *v = newVector(&tracker);

    v->push_back(v, "ccc");
    v->push_back(v, "ddd");
    v->push_back(v, "aaa");
    v->push_back(v, "fff");
    v->push_back(v, "eee");
    v->push_back(v, "bbb");

    vector_sort_function(v, my_voidcmp);

    vector_reverse_function(v);

    vector_iterator it = NULL;
    for (it = v->begin(v);
        it != v->end(v); it = it->next) {
        printf("value: %s\n", (char *)(it->data));
    }


    my_free_all(&tracker);
}
