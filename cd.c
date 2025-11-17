/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

char *recup_home_path(char **envir)
{
    for (int i = 0; envir[i] != NULL; i++) {
        if (my_strncmp(envir[i], "HOME=", 5) == 0) {
            return &envir[i][5];
        }
    }
    return NULL;
}

int exec_cd_command(char **command_line, char *cd_comm, char **envir)
{
    if (my_strcmp(command_line[0], "cd") == 0) {
        if (chdir(command_line[1]) == -1) {
            perror("cd fails\n");
            return 0;
        }
    }
    return 1;
}

int exec_cd_com(char **command_line, char *cd_comm, char **envir)
{
    if (my_strcmp(command_line[0], "cd") == 0) {
        if (chdir(cd_comm) == -1) {
            perror("cd fails\n");
            return 0;
        }
    }
    return 1;
}

int compt_arg_stdin(char *line)
{
    int nb_str = 0;

    nb_str = bufstr(line, ' ');
    return nb_str - 1;
}

int cd_command(char **command_line, char **envir, char *line)
{
    char *cd_comm = recup_home_path(envir);

    
    if (compt_arg_stdin(line) == 1)
        exec_cd_command(command_line, cd_comm, envir);
    if (compt_arg_stdin(line) == 0)
        exec_cd_com(command_line, cd_comm, envir);
    return 0;
}
