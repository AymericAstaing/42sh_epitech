/*
** EPITECH PROJECT, 2017
** Ints flags
** File description:
** Intergers flags
*/

#include	"printf.h"

int		f_int(va_list *list)
{
	return (put_long((long)(va_arg(*list, int))));
}

int		f_long(va_list *list)
{
	return (put_long(va_arg(*list, long)));
}

int		f_uint(va_list *list)
{
	return (put_ulong((unsigned long)(va_arg(*list, unsigned int))));
}

int		f_ulong(va_list *list)
{
	return (put_ulong(va_arg(*list, unsigned long)));
}
