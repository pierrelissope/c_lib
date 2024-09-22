#include <string.h>
#include <stdio.h>
#include "my_stdlib.h"

int main()
{
    alloc_tracker tracker = new_tracker();

    for (int i = 0; i < 100; ++i) {
        void *val = my_malloc(20, &tracker);
        strcpy(val, "Hello my_friend");
        my_realloc(val, 16, &tracker);
        printf("value: %s\n", (char *)val);
    }
    printf("hello world\n");
    my_free_all(&tracker);
}
