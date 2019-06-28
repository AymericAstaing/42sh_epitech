/*
** EPITECH PROJECT, 2017
** Dec flags
** File description:
** Decimal flags
*/

#include	"printf.h"

int		f_dec(va_list *list)
{
	return (put_base((unsigned long)(va_arg(*list, unsigned int)), C_DEC));
}

int		f_ldec(va_list *list)
{
	return (put_base(va_arg(*list, unsigned long), C_DEC));
}
