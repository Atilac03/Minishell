/*
** EPITECH PROJECT, 2022
** src.h
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_

struct returns {
    int ret;
};

int my_putstr(char const *str);
int my_putchar(char c);
void parse_arg(char *argv);
int analyse_commands(char *buffer, char *envp[], struct returns *ret);
void do_ls(char **args);
int parse_ls(char *buffer, int i);
char **parse_env(char **env);
int do_cd(char *path);
int do_pwd(int isZeroArg);
int is_env(char *buffer, char *envp[], int j, struct returns *ret);
int is_setenv(char *buffer, char *envp[], int j, struct returns *ret);
char **parse_args_return(char *argv);
int do_env(char *buffer, int i, char *envp[]);
int do_setenv(char *buffer, char *envp[], int i);
void find_env(char *buffer, char **envp);

#endif /* !SRC_H_ */
