/*
** EPITECH PROJECT, 2024
** hhh
** File description:
** strlen
*/

#include "../mysh.h"

int buflen(char *len)
{
    int a = 0;

    while (len[a] != '\0') {
        a++;
    }
    return a;
}
