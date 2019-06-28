/*
** EPITECH PROJECT, 2017
** Pointer
** File description:
** Display ptr
*/

#include	"printf.h"

int		put_ptr(void const *ptr)
{
	int	size = 0;

	if ((long)(ptr)) {
		size += put_str("0x");
		size += put_base((long)(ptr), C_HEX);
	} else
		return (put_str(C_NIL));
	return (size);
}
