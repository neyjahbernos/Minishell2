/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_itoa.c
*/

#include <stdlib.h>
#include "../mysh.h"

int intlen(int nb)
{
    int i = 1;

    if (nb < 0)
        nb = -nb;
    while (nb > 1) {
        nb /= 10;
        i++;
    }
    return i;
}

char *fill_result(long nb, char *result, int negative)
{
    int i = 0;

    for (; nb >= 1; i++) {
        result[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    if (negative == 1)
        result[i] = '-';
    result[i + negative] = '\0';
    return result;
}

char *my_itoa(long nb)
{
    char *result;
    int negative = 0;

    if (nb == 0) {
        result = malloc(sizeof(char) * 2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    if (nb < 0) {
        nb = nb * -1;
        negative = 1;
        result = malloc(sizeof(char) * (intlen(nb) + 2));
    } else {
        result = malloc(sizeof(char) * (intlen(nb) + 1));
    }
    result = fill_result(nb, result, negative);
    return reverse_string(result);
}
