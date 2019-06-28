/*
** EPITECH PROJECT, 2017
** Hex flags
** File description:
** Hexadecimal flags
*/

#include	"printf.h"

int		f_hex(va_list *list)
{
	return (put_base((unsigned long)(va_arg(*list, unsigned int)), C_HEX));
}

int		f_lhex(va_list *list)
{
	return (put_base(va_arg(*list, unsigned long), C_HEX));
}

int		f_mhex(va_list *list)
{
	return (put_base((unsigned long)(va_arg(*list, unsigned int)), C_MHEX));
}

int		f_mlhex(va_list *list)
{
	return (put_base(va_arg(*list, unsigned long), C_MHEX));
}
