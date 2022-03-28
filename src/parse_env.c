/*
** EPITECH PROJECT, 2022
** parse_env.c
** File description:
** file to parse through the env variable
*/

#include "src.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char **parse_env(char **env)
{
    int j = 0;
    char **my_env = malloc(sizeof(char *) * 4096);
    for (int i = 0; env[i] != NULL; i++) {
        my_env[i] = malloc(sizeof(char *) * 4096);
        for (; env[i][j] != '\0'; j++) {
            my_env[i][j] = env[i][j];
        }
        j = 0;
    }
    return my_env;
}
