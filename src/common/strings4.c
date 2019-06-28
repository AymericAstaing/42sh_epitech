/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Strings 4
*/

#include	"printf.h"
#include	"shell.h"

char		*str_cat(const char *s1, const char *s2)
{
	char	*res = NULL;
	int	size = len(s1) + len(s2);
	int	i = 0;

	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	for (; s1 && s1[i]; i++)
		res[i] = s1[i];
	for (int j = 0; s2 && s2[j]; i++, j++)
		res[i] = s2[j];
	res[i] = '\0';
	return (res);
}

int		mult_str_start_eq(const char *str, const char **list)
{
	if (!(str) || !(list))
		return (FALSE);
	for (int i = 0; list[i]; i++) {
		if (str_start_eq(str, list[i]))
			return (TRUE);
	}
	return (FALSE);
}

int		add_elem_to_tab(char ***old_tab, int new_size, char *arg)
{
	char **new = new_size ? malloc(sizeof(char *) * (new_size + 1)) : NULL;
	char **tab = old_tab ? *old_tab : NULL;
	int i = 0;

	if (!(new))
		return (ERROR);
	for (; tab && tab[i]; i++)
		new[i] = tab[i];
	new[i++] = arg;
	new[i] = NULL;
	check_free((void *)(old_tab));
	*old_tab = new;
	return (SUCCESS);
}

int		str_remove_op(char **old, const char *op)
{
	char *str = old ? *old : NULL;
	int count = get_op_number(str, op);
	char *new = count ? malloc(sizeof(char) * (len(str) - count)) : NULL;
	int j = 0;

	if (!(str) || !(count) || !(new))
		return (count ? ERROR : SUCCESS);
	for (int i = 0; str[i]; i++) {
		if (!(is_op(str[i], op)))
			new[j++] = str[i];
	}
	new[j] = '\0';
	check_free((void *)(old));
	*old = new;
	return (SUCCESS);
}

int		get_op_number(const char *str, const char *op)
{
	int	count = 0;

	if (!(str))
		return (0);
	for (int i = 0; str[i]; i++)
		count += is_op(str[i], op) ? 1 : 0;
	return (count);
}