/*
** EPITECH PROJECT, 2024
** PROJET
** File description:
** my_strlen.c
*/
#include "../mysh.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
