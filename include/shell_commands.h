/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Builtin commands
*/

#ifndef SHELL_COMMANDS_H_
	#define SHELL_COMMANDS_H_

#include	"shell.h"

#define			C_BASE_CMD_NB		5

static const base_command_t	C_BASE_CMD[C_BASE_CMD_NB] = {
	{ "cd", fct_cd },
	{ "exit", fct_exit },
	{ "env", fct_env },
	{ "setenv", fct_setenv },
	{ "unsetenv", fct_unset }
};

#endif /* !SHELL_COMMANDS_H_ */
