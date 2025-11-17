/*
** EPITECH PROJECT, 2025
** mysh.c
** File description:
** mysh.c
*/

#include "mysh.h"
#include <stdio.h>

int play_prompt(int a)
{
    if (isatty(stdin->_fileno))
        my_putstr("[minishell:~$]");
    return 0;
}

int size_of_paths(char **command_line)
{
    int size = 0;

    for (int a = 0; command_line[a] != NULL; a++) {
        size = my_strlen(command_line[a]);
    }
    return size;
}

static char *test_path(char *line, char **paths, char **command_line)
{
    int n = 0;
    char *pathname;

    pathname = malloc(sizeof(char)* n + size_of_paths(command_line));
    for (int e = 0; paths[e] != NULL; e++) {
        n = my_strlen(paths[e]);
        pathname = my_strcat(paths[e], "/");
        pathname = my_strcat(pathname, command_line[0]);
        if (access(pathname, F_OK) == 0) {
            return pathname;
        }
    }
}

static char *cut_path(char **command_line, char **envir, char *line)
{
    char **paths = NULL;
    char *good_path;

    if (envir[0] == NULL)
        return NULL;
    for (int i = 0; envir[i] != NULL; i++) {
        if (my_strncmp(envir[i], "PATH=", 5) == 0) {
            paths = str_to_words_array(envir[i] + 5, ':');
            break;
        }
    }
    good_path = test_path(line, paths, command_line);
    return good_path;
}

static int fork_pathname(char *pathname, char **envir, char **command_line)
{
    pid_t child;
    int status = 0;

    child = fork();
    if (child == 0) {
        execve(pathname, command_line, envir);
        exit(1);
    } else {
        waitpid(child, &status, 0);
    }
}

static void exec_command(char *line, char **envir)
{
    char **command_line = NULL;
    int n = my_strlen(line);
    char *pathname = NULL;
    char **commands = NULL;

    line = str_clean(line);
    command_line = str_to_words_array(line, ' ');
    pathname = cut_path(command_line, envir, line);
    cd_command(command_line, envir, line);
    setenv_command(command_line, line, envir, pathname);
    fork_pathname(pathname, envir, command_line);
}

int exec_semicolons(char *line, char **envir)
{
    char **command_semi = str_to_words_array(line, ';');

    for (int i = 0; command_semi[i] != NULL; i++) {
        exec_command(command_semi[i], envir);
    }
    return 0;
}

static int mysh(int argc, char **argv, char **env, char **paths)
{
    char **envir = env;
    int a = 0;
    char *line = NULL;
    size_t len = 0;
    int flag = 1;

    while (flag) {
        play_prompt(a);
        if (getline(&line, &len, stdin) == -1)
            break;
        line = str_clean(line);
        line[my_strlen(line) - 1] = '\0';
        if (my_strcmp("exit", line) == 0)
            flag = 0;
        exec_semicolons(line, envir);
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    char **commands;
    int a = 0;

    mysh(argc, argv, env, commands);
    return 0;
}
