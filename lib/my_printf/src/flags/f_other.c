/*
** EPITECH PROJECT, 2017
** Other
** File description:
** Other flags
*/

#include	"printf.h"

int		f_percent(va_list *list)
{
	if (!(list))
		return (0);
	return (put_str("%"));
}
