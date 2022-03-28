/*
** EPITECH PROJECT, 2022
** doCd.c
** File description:
** file to execute the cd command
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

int set_pwd(void)
{
    return 0;
}

char **parse_args_return(char *argv)
{
    char **arg;
    int j = 0;
    int k = 0;

    arg = malloc(sizeof(char) * 4096);
    arg[0] = malloc(sizeof(char) * 4096);
    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] == ' ') {
            j++;
            k = 0;
            i++;
            arg[j] = malloc(sizeof(char) * 4096);
        }
        if (argv[i] != '\n')
            arg[j][k] = argv[i];
        k++;
    }
    return arg;
}

int do_cd(char *path)
{
    int ret;
    char **arg = parse_args_return(path);
    if (arg[2] == NULL || arg[2] == ' ') {
        if (arg[1][0] == '~' && arg[1][1] == NULL)
            ret = chdir("/home/atilac");
        else
            ret = chdir(arg[1]);
    } else
        my_putstr("cd: Too many arguments.\n");
    if (ret == -1) {
        my_putstr(arg[1]);
        my_putstr(": ");
        my_putstr(strerror(errno));
        my_putstr(".\n");
    }
    else
        set_pwd();
    return (0);
}
