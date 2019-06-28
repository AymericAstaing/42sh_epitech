/*
** EPITECH PROJECT, 2017
** Floats flags
** File description:
** Floats flags
*/

#include	"printf.h"

int		f_double(va_list *list)
{
	return ((long double)(put_double(va_arg(*list, double))));
}

int		f_ldouble(va_list *list)
{
	return (put_double(va_arg(*list, long double)));
}
