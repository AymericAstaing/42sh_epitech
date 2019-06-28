/*
** EPITECH PROJECT, 2018
** Common
** File description:
** String 2
*/

#include	"shell.h"
#include	"printf.h"

static int	get_tab_size(const char *str, const char *op);
static int	add_word(char **tab, const char *str, const char *op);
static char	**clean_exit(char ***tab);

char		**str_to_tab(const char *str, const char *op)
{
	int	size	= get_tab_size(str, op);
	char	**tab	= size ? malloc(sizeof(char *) * (size + 1)) : NULL;
	int	word	= 0;
	int	i	= 0;

	if (!(tab))
		return (NULL);
	do {
		tab[word] = NULL;
		for (; is_op(str[i], op); i++);
		if (!(add_word(&tab[word], str + i, op)))
			return (clean_exit(&tab));
		i += str_len_separators(tab[word], op);
		word++;
	} while (str[i]);
	tab[word] = NULL;
	return (tab);
}

int		destroy_tab(char ***old)
{
	char	**tab = *old;

	if (!(tab))
		return (0);
	for (int i = 0; tab[i]; i++)
		check_free((void *)(&tab[i]));
	check_free((void *)(old));
	return (0);
}

static int	get_tab_size(const char *str, const char *op)
{
	int	size = 0;

	if (!(str))
		return (0);
	if (*str && !(is_op(*str, op)))
		size++;
	for (int i = 0; str[i]; i++) {
		if (is_op(str[i], op))
			size++;
	}
	return (size);

}

static int	add_word(char **tab, const char *str, const char *op)
{
	*tab = str_dup_separators(str, op);
	if (!(tab))
		return (ERROR);
	return (SUCCESS);
}

static char	**clean_exit(char ***old)
{
	destroy_tab(old);
	return (NULL);
}