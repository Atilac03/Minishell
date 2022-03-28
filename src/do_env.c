/*
** EPITECH PROJECT, 2022
** doEnv.c
** File description:
** file to execute env command
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int do_env(char *buffer, int i, char *envp[])
{
    if (buffer[i] != '\n') {
        my_putstr("env: ‘");
        for (; buffer[i] != '\n'; i++)
            my_putchar(buffer[i]);
        my_putstr("’: No such file or directory\n");
    } else
        for (int i = 0; envp[i] != NULL; i++) {
            my_putstr(envp[i]);
            my_putchar('\n');
        }
    return (0);
}
