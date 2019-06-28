/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Get number
*/

#include	"shell.h"

int		get_nb(const char *str)
{
	int	res	= 0;
	int	i	= 0;

	if (!(str))
		return (0);
	for (; str[i] && !(IS_DIGIT(str[i])); i++);
	for (; IS_DIGIT(str[i]); i++)
		res = res * 10 + str[i] - '0';
	return (res);
}