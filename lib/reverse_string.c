/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** reverse_string.c
*/

#include "../mysh.h"

char *reverse_string(char *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int len = my_strlen(str) - 1;

    for (; i < my_strlen(str); i++) {
        result[i] = str[len];
        len--;
    }
    result[i] = '\0';
    return result;
}
