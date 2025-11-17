/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my_putstrA
*/

#include "../mysh.h"

int my_putstr(char const *arr)
{
    int i = 0;

    while (arr[i] != '\0') {
        my_putchar(arr[i]);
        i = i + 1;
    }
    return 0;
}
