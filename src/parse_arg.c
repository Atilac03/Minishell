/*
** EPITECH PROJECT, 2022
** print_art.c
** File description:
** file to print arg (step 3 bootstrap)
*/

#include "src.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void parse_arg(char *argv)
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
    do_ls(arg);
}
