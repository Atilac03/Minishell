/*
** EPITECH PROJECT, 2022
** analyseCommands2.c
** File description:
** second file to analyse commands on the input
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int is_env(char *buffer, char *envp[], int j, struct returns *ret)
{
    if (buffer[j] == 'e' && buffer[j + 1] == 'n' && buffer[j + 2] == 'v') {
        int i = j + 3;
        if (buffer[i] == ' ') {
            for (; buffer[i] == ' '; i++)
                i = i;
        }
        do_env(buffer, i, envp);
        ret->ret++;
    }
    return (0);
}

int is_setenv(char *buffer, char *envp[], int j, struct returns *ret)
{
    if (buffer[j] == 's' && buffer[j + 1] == 'e' && buffer[j + 2] == 't' &&
    buffer[j + 3] == 'e' && buffer[j + 4] == 'n' && buffer[j + 5] == 'v') {
        int i = j + 6;
        char **parse_arg = parse_args_return(buffer);
        if (parse_arg[3] != NULL) {
            my_putstr("setenv: Too many arguments.\n");
            ret->ret++;
            return 0;
        }
        if (parse_arg[1] == NULL) {
            for (int i = 0; envp[i] != NULL; i++) {
                my_putstr(envp[i]);
                my_putchar('\n');
            }
        } else
            do_setenv(parse_arg[1], envp, i);
        ret->ret++;
    }
    return (0);
}
