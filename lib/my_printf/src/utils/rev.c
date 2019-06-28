/*
** EPITECH PROJECT, 2017
** Revserse str
** File description:
** Rev str
*/

#include	"printf.h"

void		rev(char *str)
{
	int	size = len(str) - 1;
	char	tmp;

	for (int i = 0; i < size - i; i++) {
		tmp = str[i];
		str[i] = str[size - i];
		str[size - i] = tmp;
	}
}
