/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** put char
*/

#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
