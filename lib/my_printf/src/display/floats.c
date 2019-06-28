/*
** EPITECH PROJECT, 2017
** Floats
** File description:
** Display floats
*/

#include	"printf.h"

static long	pow_ten(long);

int		put_double(long double nb)
{
	long double	tmp = (long double)((unsigned long)(nb < 0 ? -nb : nb));
	long double	ten = (long double)(pow_ten(6));
	int		size = 0;

	if (nb) {
		size += put_long((long)(nb));
		size += put_char('.');
		nb = nb < 0 ? -nb : nb;
		size += put_long((long)(nb * ten - tmp * ten));
	} else
		return (put_str("0.000000"));
	return (size);
}

static long	pow_ten(long x)
{
	if (x < 0)
		return (0);
	if (!(x))
		return (1);
	return (10 * pow_ten(x - 1));
}
