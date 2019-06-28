/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Errors header
*/

#ifndef SHELL_ERRORS_H_
	#define SHELL_ERRORS_H_

#include	"shell.h"

typedef		struct error_s {
	int	id;
	int	has_cmd;
	int	has_str;
	int	ret;
	char	*format;
}		error_t;

static const error_t	C_ERRORS[TOTAL_ERRORS] = {
	{ NO_FILE_DIRECTORY,	TRUE,	TRUE,	127,
		"%s: ‘%s’: No such file or directory\n"},
	{ NO_FILE_DIRECTORY_2,	FALSE,	TRUE,	1,
		"%s: No such file or directory.\n" },
	{ TOO_MANY_ARGS,	TRUE,	FALSE,	1,
		"%s: Too many arguments.\n" },
	{ EXPR_SYNTAX,		TRUE,	FALSE,	1,
		"%s: Expression Syntax.\n" },
	{ CMD_NOT_FOUND,	TRUE,	FALSE,	1,
		"%s: Command not found.\n" },
	{ ALPHA_NUM_VAR,	TRUE,	FALSE,	1,
		"%s: Variable name must contain alphanumeric characters.\n" },
	{ AMBIGOUS_INPUT,	TRUE,	FALSE,	1,
		"Ambiguous output redirect.\n" },
	{ AMBIGOUS_OUTPUT,	TRUE,	FALSE,	1,
		"Ambiguous input redirect.\n" },
	{ NULL_CMD,		FALSE,	FALSE,	1,
		"Invalid null command.\n" },
	{ LETTER_BEGIN,		FALSE,	FALSE,	1,
		"%s: Variable name must begin with a letter.\n" }
};

#endif /* !SHELL_ERRORS_H_ */
