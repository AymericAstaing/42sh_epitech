##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## Main makefile
##

#	Root path
ROOT		=		./

#	Sources path
F_SRC		=		$(ROOT)src/

#	Binary name
NAME		=		42sh

#	Main source
SRC		=		$(F_SRC)main.c

#	Common sources
SRC		+=		$(F_SRC)common/checks.c	\
				$(F_SRC)common/strings.c	\
				$(F_SRC)common/strings2.c	\
				$(F_SRC)common/strings3.c	\
				$(F_SRC)common/strings4.c	\
				$(F_SRC)common/strings5.c	\
				$(F_SRC)common/error.c	\
				$(F_SRC)common/get_nb.c	\
				$(F_SRC)common/get_next_line.c

#	Cmd sources
SRC		+=		$(F_SRC)cmd/cmd_handler.c

#	Commands sources
SRC		+=		$(F_SRC)commands/cd.c	\
				$(F_SRC)commands/exit.c	\
				$(F_SRC)commands/env.c	\
				$(F_SRC)commands/unset.c	\
				$(F_SRC)commands/setenv.c

#	Env sources
SRC		+=		$(F_SRC)env/init_env.c	\
				$(F_SRC)env/get_env.c	\
				$(F_SRC)env/show_env.c	\
				$(F_SRC)env/format_env.c

#	Shell sources
SRC		+=		$(F_SRC)shell/init_shell.c	\
				$(F_SRC)shell/prompt.c	\
				$(F_SRC)shell/shell_loop.c	\
				$(F_SRC)shell/get_shell.c

#	Lexer sources
SRC		+=		$(F_SRC)lexer/init_node.c	\
				$(F_SRC)lexer/get_node.c	\
				$(F_SRC)lexer/lexer_vars.c	\
				$(F_SRC)lexer/get_next_node.c	\
				$(F_SRC)lexer/lexer_strings.c	\
				$(F_SRC)lexer/build_tree.c	\
				$(F_SRC)lexer/show_node.c	\
				$(F_SRC)lexer/check_tree.c

#	Prompt
SRC		+=		$(F_SRC)prompt/customize.c

#	Parser
SRC		+=		$(F_SRC)parser/exec_command.c	\
				$(F_SRC)parser/operator_manager.c	\
				$(F_SRC)parser/operator_manager2.c	\
				$(F_SRC)parser/file.c	\
				$(F_SRC)parser/set_command.c	\
				$(F_SRC)parser/set_command2.c	\
				$(F_SRC)parser/exec_command_utils.c

#	Compile every source file to .o
OBJ		=		$(SRC:.c=.o)

#	Compiler
CC		=		cc

#	Compilation flags
CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=gnu99	\
				-I $(ROOT)include/

#	Libraries links
LDFLAGS		+=		-L $(ROOT)lib/ -l my

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
