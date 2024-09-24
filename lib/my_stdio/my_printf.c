/*
** EPITECH PROJECT, 2024
** printf
** File description:
** printf
*/


#include "../include/my_stdio.h"
#include "../include/my_string.h"

#include <stdarg.h>

static int check_single(char *str, int i)
{
    if (str[i + 1] != 'd' && str[i + 1] != 'c' &&
        str[i + 1] != 's' && str[i + 1] != 'i' &&
        str[i + 1] != '%') {
        return 1;
    }
    return 0;
}

int len_nb(int nb)
{
    int count = 0;

    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return count;
}

static int isntvar(char *str, int i)
{
    int result = 1;

    if (str[i + 1] == '\0') {
        return 1;
    } else if (str[i] == '%') {
        result = check_single(str, i);
    }
    return result;
}

static int display_var2(va_list args, char *str, int i)
{
    int a = 0;

    if (str[i + 1] == 'd' || str[i + 1] == 'i') {
        a = va_arg(args, int);
        my_put_nbr(a);
        return (len_nb(a));
    }
    if (str[i + 1] != '\0' && str[i + 1] == '%') {
        my_putchar('%');
    }
    return 1;
}

static int display_var(va_list args, char *str, int i)
{
    int res = 1;
    char *string;

    res = display_var2(args, str, i);
    if (str[i + 1] == 's') {
        string = va_arg(args, char *);
        if (string == NULL) {
            my_putstr("(null)");
        } else {
            my_putstr(string);
            res = my_strlen(string);
        }
    }
    if (str[i + 1] == 'c')
        my_putchar(va_arg(args, int));
    return res;
}

int mini_printf(char *str, ...)
{
    va_list args;
    int count = 0;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (isntvar(str, i) == 1) {
            my_putchar(str[i]);
            count++;
        }
        if (isntvar(str, i) == 0) {
            count = count + display_var(args, str, i);
            i++;
        }
    }
    va_end(args);
    return count;
}
