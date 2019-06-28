/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Error
*/

#include	"printf.h"
#include	"shell_errors.h"

int		error(int id, const char *cmd, const char *str)
{
	if (C_ERRORS[id].has_cmd && C_ERRORS[id].has_str)
		my_printf(C_ERRORS[id].format, cmd, str);
	if (C_ERRORS[id].has_cmd && !(C_ERRORS[id].has_str))
		my_printf(C_ERRORS[id].format, cmd);
	if (!(C_ERRORS[id].has_cmd) && C_ERRORS[id].has_str)
		my_printf(C_ERRORS[id].format, str);
	if (!(C_ERRORS[id].has_cmd) && !(C_ERRORS[id].has_str))
		my_printf(C_ERRORS[id].format);
	return (C_ERRORS[id].ret);
}