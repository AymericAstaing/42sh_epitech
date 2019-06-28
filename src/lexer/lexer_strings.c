/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Lexer strings
*/

#include	"shell_lexer_vars.h"

static int	get_word_separator(const char *str, int old_i);
static char	*get_checked_word(const char *str, int *i, int new_i);
static void	change_states(const char *str, int *in_quote, int *is_char_op,
				char *quote_char);

char		*get_word(const char *str, int *old_i)
{
	int	i	= old_i ? *old_i : 0;
	int	check	= skip_space(str, &i);
	int	new_i	= check ? get_word_separator(str, i) : '\0';
	char	*word	= get_checked_word(str, &i, new_i);

	if (!(word))
		return (NULL);
	if (old_i)
		*old_i = i + new_i;
	str_remove_op(&word, C_QUOTES_CHARS);
	return (word);
}

int		skip_space(const char *str, int *old_i)
{
	int	i = old_i ? *old_i : 0;

	if (!(str) || !(str[i]))
		return (ERROR);
	for (; str[i]; i++) {
		if (!(is_op(str[i], C_SPACES_CHARS)))
			break;
	}
	if (old_i)
		*old_i = i;
	return (SUCCESS);
}

static int	get_word_separator(const char *input, int old_i)
{
	const char *str	= input + old_i;
	int i		= 0;
	int quote	= FALSE;
	int is_char_op	= FALSE;
	char quote_char	= '\0';

	if (!(str))
		return (ERROR);
	for (; str[i]; i++) {
		change_states(str + i, &quote, &is_char_op, &quote_char);
		if (is_char_op && !(i))
			return ((str[0] == str[1] ? 2 : 1));
		if ((is_op(str[i], C_SPACES_CHARS) && !(quote)) || is_char_op)
			return (i);
	}
	return (i);
}

static void	change_states(const char *str, int *in_quote, int *is_char_op,
				char *quote_char)
{
	*is_char_op = mult_str_start_eq(str, C_OPERATORS);
	if (is_op(*str, C_QUOTES_CHARS)) {
		if (*in_quote && *quote_char == *str)
			*in_quote = FALSE;
		else if (!(*in_quote)) {
			*in_quote = TRUE;
			*quote_char = *str;
		}
	}
}

static char	*get_checked_word(const char *str, int *i, int new_i)
{
	if (is_op(str[*i], C_QUOTES_CHARS))
		*i += 1;
	return (nstr_dup(str + *i, new_i));
}