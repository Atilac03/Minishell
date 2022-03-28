/*
** EPITECH PROJECT, 2022
** doPwd.c
** File description:
** file to execute pwd command
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int do_pwd(int isZeroArg)
{
    char buf[4069];

    if (isZeroArg == 1)
        my_putstr("pwd: ignoring non-option arguments\n");
    getcwd(buf, sizeof(buf));
    my_putstr(buf);
    my_putchar('\n');
    return (0);
}
