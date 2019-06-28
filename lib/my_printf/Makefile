NAME		=		libmy.a

ROOT		=		./

#	Core sources
SRC		=		$(ROOT)src/core/my_printf.c	\
				$(ROOT)src/core/display_arg.c

#	Display sources
SRC		+=		$(ROOT)src/display/floats.c	\
				$(ROOT)src/display/ints.c	\
				$(ROOT)src/display/ptr.c	\
				$(ROOT)src/display/str.c


#	Flags sources
SRC		+=		$(ROOT)src/flags/f_bi.c	\
				$(ROOT)src/flags/f_dec.c	\
				$(ROOT)src/flags/f_floats.c	\
				$(ROOT)src/flags/f_hex.c	\
				$(ROOT)src/flags/f_ints.c	\
				$(ROOT)src/flags/f_oct.c	\
				$(ROOT)src/flags/f_other.c	\
				$(ROOT)src/flags/f_ptr.c	\
				$(ROOT)src/flags/f_str.c

#	Utils sources
SRC		+=		$(ROOT)src/utils/len.c	\
				$(ROOT)src/utils/rev.c	\
				$(ROOT)src/utils/strcp.c


OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=c99 -I $(ROOT)include/

CC		=		cc

all:				$(NAME)

$(NAME):			$(OBJ)
				ar rc -o $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:				clean
				rm -f $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
