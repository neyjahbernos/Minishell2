/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** str_clean.c
*/

#include <stddef.h>
#include <stdlib.h>

int check_conditions(char *line, int i, int e)
{
    int space = 0;
    int condition = 0;

    if (line[i] == ' ' && line[i + 1] == ' ') {
        condition = 1;
    }
    if (line[i] == ' ' && line[i + 1] == '\0') {
        condition = 1;
    }
    if (line[i] == ' ' && line[i + 1] == '\n') {
        condition = 1;
    }
    if (line[i] == ' ' && e == 0) {
        condition = 1;
    }
    return condition;
}

char *str_clean(char *line)
{
    char *result = NULL;
    char tab = '\t';
    int e = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == tab)
            line[i] = ' ';
    for (int i = 0; line[i] != '\0'; i++)
        if (check_conditions(line, i, e) == 0) {
            e++;
        }
    result = malloc(sizeof(char) * (e + 1));
    e = 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (check_conditions(line, i, e) == 0) {
            result[e] = line[i];
            e++;
        }
    return result;
}
