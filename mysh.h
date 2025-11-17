/*
** EPITECH PROJECT, 2025
** stumper_includes
** File description:
** stumper
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

#ifndef STUMPER_H
   #define STUMPER_H

int implem_setenv(char **command_line, char **envir);
static int print_env(char **envir, char **command_line);
char *my_strdup(char *src);
int setenv_command(char **command_line, char *line,
    char **envir, char *pathname);
int compt_arg_stdin(char *line);
int cd_command(char **command_line, char **envir, char *line);
char *str_clean(char *line);
char *my_itoa(long nb);
int my_strncmp(char *s1, char *s2, int n);
char *reverse_string(char *str);
int my_strcmp(const char *str, char *str2);
void my_putchar(char c);
int my_putstr(char const *arr);
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);
char **str_to_words_array(char *str, char sep);
int my_strcmp(const char *str, char *str2);
int buflen(char *len);
int bufstr(char *str, char sep);
#endif
