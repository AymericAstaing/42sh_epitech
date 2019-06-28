/*
** EPITECH PROJECT, 2017
** Bi flags
** File description:
** Binary flags
*/

#include	"printf.h"

int		f_bi(va_list *list)
{
	return (put_base((unsigned long)(va_arg(*list, unsigned int)), C_BI));
}

int		f_lbi(va_list *list)
{
	return (put_base(va_arg(*list, unsigned long), C_BI));
}
