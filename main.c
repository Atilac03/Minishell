/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main file
*/

#include "src.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sig(int signal)
{
    (void)signal;
    my_putstr("\n$> ");
}

int main(int argc, char **argv, char *envp[])
{
    struct returns ret;
    int is_term = isatty(0);
    size_t bufsize = 32;
    char *buffer = malloc(sizeof (char*) * bufsize);
    argv = argv;

    if (argc != 1)
        return (84);
    char **my_env = parse_env(envp);
    signal(SIGINT, handle_sig);
    if (is_term == 1)
        my_putstr("$> ");
    while (getline(&buffer, &bufsize, stdin) != -1) {
        ret.ret = analyse_commands(buffer, my_env, &ret);
        if (is_term == 1)
            my_putstr("$> ");
        if (ret.ret == 1)
            return (0);
    }
    return (0);
}
