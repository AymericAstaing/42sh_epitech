##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## Normal test
##

ROOT		=		../../

#	Sources path
F_SRC		=		./

NAME		=		tests

SRC		=		$(F_SRC)main_tests.c		\
				$(F_SRC)test_strlen_separator.c	\
				$(F_SRC)test_strtotab.c		\
				$(ROOT)src/common/strings.c	\
				$(ROOT)src/common/strings2.c	\
				$(ROOT)src/common/strings3.c	\
				$(ROOT)src/common/get_nb.c	\
				$(ROOT)src/common/strings4.c	\
				$(ROOT)src/common/checks.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-Wall -Wextra -pedantic -std=c99 -g3 \
				-I $(ROOT)include

LDFLAGS		+=		-L $(ROOT)lib/ -l my -lgcov -lcriterion

#	Call compilation rule
all:				compile_lib $(NAME)

#	Compile every file then pack them all !
$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

compile_lib:			clean_lib
				make -C $(ROOT)lib/my_printf/
				cp $(ROOT)lib/my_printf/libmy.a $(ROOT)lib/
				cp $(ROOT)lib/my_printf/include/printf.h $(ROOT)include/

clean_lib:
				rm -rf $(ROOT)lib/printf.h
				rm -rf $(ROOT)include/printf.h
				rm -rf $(ROOT)lib/libmy.a

#	Clean object type sources
clean:
				rm -f $(OBJ)
				make -C $(ROOT)lib/my_printf/ clean

#	Clean binary
fclean:				clean_lib clean
				rm -f $(NAME)
				make -C $(ROOT)lib/my_printf/ fclean

#	Clean all then compile
re:				fclean all

.PHONY:				all clean fclean re
