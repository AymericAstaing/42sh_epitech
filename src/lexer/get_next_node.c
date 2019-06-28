/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Get next node
*/

#include	"shell_lexer_vars.h"

static node_t	*clean_exit(char **word, node_t **node);

node_t		*get_next_node(const char *str, int *old_i)
{
	int	i	= old_i ? *old_i : 0;
	node_t	*node	= NULL;
	char	*word	= get_word(str, &i);
	int	type	= identify_type(word);

	if (!(word) || !(type))
		return (clean_exit(&word, &node));
	node = get_node(type, word);
	*old_i = i;
	return (node);
}

int		identify_type(const char *word)
{
	if (!(word))
		return (N_NONE);
	else if (mult_str_start_eq(word, C_OPERATORS))
		return (N_OP);
	return (N_CMD);
}

static node_t	*clean_exit(char **word, node_t **node)
{
	destroy_node(node);
	check_free((void *)(word));
	return (NULL);
}