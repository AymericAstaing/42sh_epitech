/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Checks
*/

#include	"shell.h"

int		check_free(void **data)
{
	if (*data)
		free(*data);
	*data = NULL;
	return (0);
}