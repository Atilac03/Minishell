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

int do_setenv(char *buffer, int i)
{
    int ret;
    int j = 0;
    char *firstarg = malloc(sizeof(char *) * 4096);
    char *value = "TESTVALUE";

    for (; buffer[i] != ' '; i++) {
        if (buffer[i] == '\n') {
            ret = setenv(firstarg, value, 1);
            if (ret == 0)
                return (0);
            else if (ret == -1 ) {
                printf("didnt work\n");
                return (0);
            }
        }
        else
            firstarg[j] = buffer[i];
        j++;
    }
    return 0;
}
