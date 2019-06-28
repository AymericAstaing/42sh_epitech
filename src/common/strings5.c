/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Strings 5
*/

#include	"shell.h"

char		*nstr_dup(const char *str, int target)
{
	char	*new = target ? malloc(sizeof(char) * (target + 1)) : NULL;

	if (!(new))
		return (NULL);
	for (int i = 0; str[i] && i < target; i++)
		new[i] = str[i];
	new[target] = '\0';
	return (new);
}