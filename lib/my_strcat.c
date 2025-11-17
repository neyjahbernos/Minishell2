/*
** EPITECH PROJECT, 2024
** PROJET
** File description:
** my_strcat.c
*/
#include "../mysh.h"

char *my_strcat(char *dest, char *src)
{
    int a = 0;
    int e = 0;
    char *result = malloc(sizeof(char) *
    (unsigned int)(my_strlen(dest) + my_strlen(src) + 1));
    int i;

    if (dest == NULL)
        return src;
    if (src == NULL)
        return dest;
    for (i = 0; dest[i] != '\0'; i++) {
        result[i] = dest[a];
        a++;
    }
    for (e = 0; src[e] != '\0'; e++) {
        result[i] = src[e];
        i++;
    }
        result[i] = '\0';
    return result;
}
