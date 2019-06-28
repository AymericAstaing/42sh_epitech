/*
** EPITECH PROJECT, 2017
** Oct flags
** File description:
** Octal flags
*/

#include	"printf.h"

int		f_oct(va_list *list)
{
	return (put_base((unsigned long)(va_arg(*list, unsigned int)), C_OCT));
}

int		f_loct(va_list *list)
{
	return (put_base(va_arg(*list, unsigned long), C_OCT));
}
