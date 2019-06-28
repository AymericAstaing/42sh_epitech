/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Printf main entry
*/

#include	"printf.h"

int		my_printf(const char *format, ...)
{
	va_list	list;
	int	size = 0;

	va_start(list, format);
	for (int i = 0; format[i];) {
		if (format[i] == '%')
			size += display_arg(format, &i, &list);
		else
			size += put_char(format[i++]);
	}
	va_end(list);
	return (size);
}
