/*
** EPITECH PROJECT, 2025
** strcmp
** File description:
** azert
*/

#include "../mysh.h"

int my_strcmp(const char *str, char *str2)
{
    int i = 0;

    if (str == NULL || str2 == NULL)
        return 84;
    while (str[i] == str2[i] && str[i] && str2[i]) {
    i++;
    }
    return str[i] - str2[i];
}
