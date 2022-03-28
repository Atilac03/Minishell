##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/my_putchar.c	\
		src/my_putstr.c	\
		src/exec_ls.c	\
		src/parse_arg.c	\
		src/analyse_commands.c	\
		src/analyse_commands2.c	\
		src/do_cd.c	\
		src/do_pwd.c	\
		src/do_env.c	\
		src/do_setenv.c	\
		src/parse_env.c

MAIN	=	main.c

OBJ	=	$(SRC:.c=.o)

OBJMAIN	=	$(MAIN:.c=.o)

CFLAGS += -Wall -Wextra -W

HEADER_PATH	=	./include

CPPFLAGS	=	-I./include

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)	$(OBJMAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS) $(LFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJMAIN)

fclean:	clean
	$(RM) $(NAME)
	$(RM) *~
	$(RM) *.o

re: fclean all
