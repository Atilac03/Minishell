/*
** EPITECH PROJECT, 2022
** do_setenv.c
** File description:
** file to execute setenv command
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char **replace_env(char *buffer, char **envp, int i)
{
    return envp;
}

void find_env(char *buffer, char **envp)
{
    int j = 0;
    int is_exist_env = 0;
    for (int i = 0; envp[i] != NULL; i++) {
        for (j = 0; buffer[j] != '='; j++) {
            if (buffer[j] == '\0')
                break;
            if (buffer[j] == envp[i][j])
                is_exist_env = 1;
            else {
                is_exist_env = 0;
                break;
            }
        }
        if (envp[i][j] != '=')
            is_exist_env = 0;
        if (is_exist_env == 1)
            break;
    }
}

int do_setenv(char *buffer, char *envp[], int i)
{
    buffer = buffer;
    envp = envp;
    i = i;
    find_env(buffer, envp);
    return 0;
}
