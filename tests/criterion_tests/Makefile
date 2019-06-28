##
## EPITECH PROJECT, 2017
## 42sh
## File description:
## Makefile
##

## @Compilation

SRC		=	./test_strcat.c			\
			./test_getnbr.c			\
			./tests_string.c		\
			./../../src/common/strings.c	\
			./../../src/common/strings2.c	\
			./../../src/common/strings3.c	\
			./../../src/common/strings4.c	\
			./../../src/common/checks.c	\
			./../../src/common/get_nb.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc -o

## @Variables

NAME		=	unit_tests

INCLUDE		=	../../include

## @Flags

CFLAGS		+=	-Wall -Wextra -pedantic

CPPFLAGS	+=	-I $(INCLUDE)

LDFLAGS		+=	-L../../lib/ -lmy -lcriterion -lgcov

## @Make

REMOVE		=	rm -f

CLEAN		=	clean

FCLEAN		=	fclean

ALL		=	all

## @Job

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LDFLAGS)

clean:
		$(REMOVE) $(OBJ)

fclean:		$(CLEAN)
		$(REMOVE) $(NAME)

re:		$(FCLEAN) $(ALL)

.PHONY:		$(ALL) $(CLEAN) $(FCLEAN) re
