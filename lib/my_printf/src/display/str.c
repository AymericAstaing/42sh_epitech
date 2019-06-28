/*
** EPITECH PROJECT, 2017
** String
** File description:
** Display string
*/

#include	"printf.h"

static int	add_zeros(char const);

int		put_char(char const c)
{
	if (c)
		write(1, &c, 1);
	return (c ? 1 : 0);

}

int		put_str(char const * const str)
{
	int	size = len(str);

	if (str)
		write(1, str, size);
	else
		return (put_str(C_NULL));
	return (size);
}

int		put_fstr(char const * const str)
{
	int	size = 0;

	if (!(str))
		return (put_str(C_NULL));
	else if (*str) {
		if (*str < 32 || *str >= 127) {
			size += put_char('\\');
			size += add_zeros(*str);
			size += put_base(*str, C_OCT);
		} else
			size += put_char(*str);
		size += put_fstr(str + 1);
	}
	return (size);
}

static int	add_zeros(char const c)
{
	if (c < 8)
		return (put_str("00"));
	else if (c < 64)
		return (put_str("0"));
	return (0);
}
