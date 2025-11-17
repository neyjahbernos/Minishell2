/*
** EPITECH PROJECT, 2024
** azertyuio
** File description:
** éazertyhujikolpm
*/

#include "../mysh.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] == s2[i]) {
            i++;
        } else {
            return -1;
        }
    }
    return 0;
}
