/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Define variables
*/

#ifndef SHELL_VARS_H_
	#define SHELL_VARS_H_

/*		Operators
	| < > || && ; ( ) { }		*/
#define		C_SPACES_CHARS		(" \t\n")
#define		C_QUOTES_CHARS		("(){}\"\"")
#define		C_OP_CHARS		("|<>&;")
#define		C_PIPE_CHAR		("|")
#define		C_REDIRECT_LEFT		("<")
#define		C_REDIRECT_RIGHT	(">")
#define		C_FILE_SEPARATOR	("/")
#define		C_SEPARATOR		(";")

#define		C_NAME_SEPARATOR	('=')
#define		C_VAR_SEPARATOR		(':')
#define		C_FILE_SEPARATOR_CHAR	('/')
#define		C_PATH			("PATH")

#define		C_LESS_ARG		("-")

#define		C_MAX_TRY_CWD		10

#define		C_CWD_BUFFER		256

#define		C_SEGFAULT_CODE		139
#define		C_FLOAT_CODE		136

#define		C_SEGFAULT		("Segmentation fault (core dumped)\n")
#define		C_FLOAT_EXCEPTION	("Floating exception (core dumped)\n")

#define		C_EXIT_MSG		("exit\n")

#define		RESET		("0")
#define		GREEN		("1;32")
#define		RED		("1;31")
#define		SKY_BLUE	("1;36")

#define		C_OP_NB		(7)

enum		error {
	NO_FILE_DIRECTORY = 0,
	NO_FILE_DIRECTORY_2,
	TOO_MANY_ARGS,
	EXPR_SYNTAX,
	CMD_NOT_FOUND,
	ALPHA_NUM_VAR,
	AMBIGOUS_INPUT,
	AMBIGOUS_OUTPUT,
	NULL_CMD,
	LETTER_BEGIN,
	TOTAL_ERRORS
};

enum	node_type {
	N_NONE,
	N_ROOT,
	N_CMD,
	N_OP,
	N_TOTAL
};

enum	node_res {
	R_NONE = -1,
	R_ERROR = -2
};

enum	file_descriptors {
	FD_IN = 0,
	FD_OUT,
	FD_TOTAL
};

enum	building_nodes {
	B_PREV = 0,
	B_NEXT,
	B_UP,
	B_OP,
	B_TOTAL
};

enum	directions {
	D_LEFT = 0,
	D_RIGHT,
	D_TOTAL
};

#endif /* !SHELL_VARS_H_ */