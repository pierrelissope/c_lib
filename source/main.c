/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdio.h>
#include "my_stdlib.h"
#include "my_vector.h"

int main(void)
{
    alloc_tracker tracker = new_tracker();
    vector *v = newVector(&tracker);

    v->push_back(v, "Papa");
    v->push_back(v, "Maman");
    v->push_back(v, "Didi");
    v->push_back(v, "Samuel");
    v->push_back(v, "Maheva");
    v->push_back(v, "Mathis");
    for (vector_iterator it = v->begin(v);
        it != v->end(v); it = it->next) {
        printf("value: %s\n", (char *)(it->data));
    }

    my_free_all(&tracker);
}
