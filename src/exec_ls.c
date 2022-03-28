/*
** EPITECH PROJECT, 2022
** exec_ls.c
** File description:
** file to exec ls
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int parse_ls(char *buffer, int i)
{
    if (buffer[i] == ' ') {
        for (; buffer[i] == ' '; i++)
            i = i;
    } else if (buffer[i] != '\n')
        return 0;
    return i;
}

void do_ls(char **args)
{
    char *argv[] = {"/bin/ls", NULL};
    char *env[] = {NULL};
    execve(argv[0], args, env);
}
