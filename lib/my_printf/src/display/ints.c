/*
** EPITECH PROJECT, 2017
** Ints
** File description:
** Display integers
*/

#include	"printf.h"

int		put_long(long nb)
{
	int	size = 1;

	if (nb < 0) {
		nb *= -1;
		put_char('-');
		size++;
	}
	if (nb > 9)
		size += put_long(nb / 10);
	put_char(nb % 10 + '0');
	return (size);
}

int		put_ulong(unsigned long nb)
{
	int	size = 1;

	if (nb > 9)
		size += put_long(nb / 10);
	put_char(nb % 10 + '0');
	return (size);
}

int		put_base(unsigned long nb, char const *B_chars)
{
	char		res[64];
	unsigned long	B = (unsigned long)(len(B_chars));
	int		i = 0;

	if (!(B_chars))
		return (0);
	do {
		res[i++] = B_chars[nb % B];
		nb /= B;
	} while (nb);
	res[i] = '\0';
	rev(res);
	return (put_str(res));
}
