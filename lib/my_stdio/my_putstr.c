/*
** EPITECH PROJECT, 2024
** putstr
** File description:
** putstr
*/

#include <unistd.h>

#include "../include/my_stdio.h"
#include "../include/my_string.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

static void printmax(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
}

static void nextfct(long n)
{
    if (n < 0 && n != -2147483648) {
        my_putchar('-');
        n = n * -1;
    }
    if (n <= 9) {
        my_putchar(n + 48);
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    }
}

void my_put_nbr(long n)
{
    if (n == 2147483647) {
        printmax();
        my_putchar('7');
        return;
    }
    if (n == -2147483648) {
        my_putchar('-');
        printmax();
        my_putchar('8');
        return;
    }
    nextfct(n);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

