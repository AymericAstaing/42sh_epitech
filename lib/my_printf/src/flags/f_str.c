/*
** EPITECH PROJECT, 2017
** Str flags
** File description:
** String flags
*/

#include	"printf.h"

int		f_str(va_list *list)
{
	return (put_str(va_arg(*list, char const * const)));
}

int		f_fstr(va_list *list)
{
	return (put_fstr(va_arg(*list, char const * const)));
}

int		f_char(va_list *list)
{
	return (put_char((char)(va_arg(*list, int const))));
}
