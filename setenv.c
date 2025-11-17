/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** setenv.c
*/

#include "mysh.h"

static int play_env(char **command_line, char **envir)
{
    if (my_strcmp(command_line[0], "setenv") == 0) {
        for (int i = 0; envir[i] != NULL; i++) {
            my_putstr(envir[i]);
            my_putchar('\n');
        }
    }
    return 0;
}

static int print_env(char **envir, char **command_line)
{
    if (my_strcmp(command_line[0], "env") == 0) {
        for (int i = 0; envir[i] != NULL; i++) {
            my_putstr(envir[i]);
        }
    }
    return 0;
}

int compt_str(char **envir)
{
    int i = 0;

    for (i = 0; envir[i] != NULL; i++) {
        i++;
    }
    return i;
}

int check_var(char **command_line, char **envir, int flag_add)
{
    int a = 0;
    char *envir_line;

    for (int i = 0; envir[i] != NULL; i++) {
        if (my_strcmp(envir[i], command_line[1]) == 0) {
            my_putstr("is already in");
            return 84;
        }
        if (my_strcmp(envir[i], command_line[1]) != 0) {
            flag_add = 1;
        }
    }
    return 0;
}

int compt_arg_comm(char **command_line)
{
    int nb_arg = 0;

    for (int i = 0; command_line[i] != NULL; i++) {
        nb_arg += 1;
    }
    return nb_arg;
}

int setenv_command(char **command_line, char *line,
    char **envir, char *pathname)
{
    int flag_add = 0;

    if (compt_arg_comm(command_line) == 1) {
        play_env(command_line, envir);
    } else if (compt_arg_comm(command_line) > 1 &&
        my_strcmp(command_line[0], "setenv") == 0) {
        check_var(command_line, envir, flag_add);
        flag_add = 0;
    }
    return 0;
}
