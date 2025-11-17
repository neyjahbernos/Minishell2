/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** rrrrrr
*/
#include <stdlib.h>
#include "../mysh.h"

int my_strlen2(char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char)*my_strlen2(src)+1);
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
