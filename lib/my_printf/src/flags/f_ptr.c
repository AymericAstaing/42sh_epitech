/*
** EPITECH PROJECT, 2017
** Ptr flags
** File description:
** Pointer flags
*/

#include	"printf.h"

int		f_ptr(va_list *list)
{
	return (put_ptr(va_arg(*list, void *)));
}
