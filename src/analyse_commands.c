/*
** EPITECH PROJECT, 2022
** analyseCommands.c
** File description:
** file to analyse commands passed
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int is_pwd(char *buffer, int j, struct returns *ret)
{
    if (buffer[j] == 'p' && buffer[j + 1] == 'w' && buffer[j + 2] == 'd') {
        int i = j + 3;
        if (buffer[i] == ' ') {
            for (; buffer[i] == ' '; i++)
                i = i;
        }
        else if (buffer[i] != '\n')
            return (0);
        if (buffer[i] == '\n') {
            do_pwd(0);
            ret->ret++;
        } else if (buffer[i] != '-' && buffer[i - 1] == ' ') {
            do_pwd(1);
            ret->ret++;
        }
    }
    return (0);
}

int is_cd(char *buffer, int j, struct returns *ret)
{
    if (buffer[j] == 'c' && buffer[j + 1] == 'd') {
        int i = j + 2;
        if (buffer[i] == ' ') {
            for (; buffer[i] == ' '; i++)
                i = i;
        }
        else if (buffer[i] != '\n')
            return (0);
        do_cd(buffer);
        ret->ret++;
    }
    return (0);
}

int is_ls(char *buffer, int j, struct returns *ret)
{
    int status;
    if (buffer[j] == 'l' && buffer[j + 1] == 's') {
        int i = j + 2;
        i = parse_ls(buffer, i);
        if (i == 0)
            return (0);
        ret->ret++;
        pid_t childPid = fork();
        waitpid(childPid, &status, 0);
        if (childPid == 0)
            parse_arg(buffer);
    }
    return (0);
}

int is_exit(char *buffer, int j)
{
    if (buffer[j] == 'e' && buffer[j + 1] == 'x' && buffer[j + 2] == 'i' &&
    buffer[j + 3] == 't') {
        int i = j + 4;
        if (buffer[i] == ' ') {
            for (; buffer[i] == ' '; i++)
                i = i;
        }
        if (buffer[i] == '\n') {
            my_putstr("exit\n");
            return (1);
        }
    }
    return (0);
}

int analyse_commands(char *buffer, char *envp[], struct returns *ret)
{
    int i = 0;
    for (; buffer[i] == ' '; i++)
        i = i;
    ret->ret = is_exit(buffer, i);
    if (ret->ret == 1)
        return (1);
    is_ls(buffer, i, ret);
    is_cd(buffer, i, ret);
    is_pwd(buffer, i, ret);
    is_env(buffer, envp, i, ret);
    is_setenv(buffer, envp, i, ret);
    if (ret->ret == 0 && buffer[0] != '\n') {
        for (int j = 0; buffer[j] != '\n'; j++) {
            if (buffer[j] == ' ')
                break;
            my_putchar(buffer[j]);
        }
        my_putstr(": Command not found.\n");
    }
    return (0);
}
