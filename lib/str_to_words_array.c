/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** str_to_words_array.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "../mysh.h"

int bufstr(char *str, char sep)
{
    int i = 0;
    int a = 0;

    while (str[a] != '\0') {
        if (str[a] == sep) {
            i++;
        }
        a++;
    }
    return i + 1;
}

char **str_to_words_array(char *str, char sep)
{
    int i = 0;
    int a = 0;
    int e = 0;
    char **board = malloc(sizeof(char *) * (bufstr(str, sep) + 1));

    board[bufstr(str, sep)] = NULL;
    while (i != bufstr(str, sep)) {
        board[i] = malloc(sizeof(char) * buflen(str) + 1);
        while (str[e] != sep && str[e] != '\0') {
            board[i][a] = str[e];
            a++;
            e++;
        }
        board[i][a] = '\0';
        e++;
        a = 0;
        i++;
    }
    return board;
}
