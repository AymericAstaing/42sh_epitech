/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Strings 3
*/

#include	"printf.h"
#include	"shell.h"

char		*str_dup_separators(const char *str, const char *op)
{
	int	size = str_len_separators(str, op);
	char	*new = size ? malloc(sizeof(char) * (size + 1)) : NULL;

	if (!(new))
		return (NULL);
	for (int i = 0; i < size; i++)
		new[i] = str[i];
	new[size] = '\0';
	return (new);
}

int		str_len_separators(const char *str, const char *op)
{
	int	size = 0;

	if (!(str))
		return (0);
	for (; str[size] && !(is_op(str[size], op)); size++);
	return (size);
}

int		is_op(char c, const char *op)
{
	if (!(op))
		return (FALSE);
	for (int i = 0; op[i]; i++) {
		if (c == op[i])
			return (TRUE);
	}
	return (FALSE);
}

void		skip_op(const char *str, int *old_i, const char *op)
{
	int	i = old_i ? *old_i : 0;

	if (!(str))
		return;
	for (; is_op(str[i], op) && str[i]; i++);
	if (old_i)
		*old_i = i;
}

int		has_op(const char *str, const char *op)
{
	if (!(str))
		return (FALSE);
	for (int i = 0; str[i]; i++) {
		if (is_op(str[i], op))
			return (TRUE);
	}
	return (FALSE);
}