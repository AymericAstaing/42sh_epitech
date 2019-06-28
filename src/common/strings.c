/*
** EPITECH PROJECT, 2018
** Common
** File description:
** Str operation with separator
*/

#include	"shell.h"
#include	"printf.h"

char		*str_dup_separator(const char *str, char separator)
{
	int	size = str_len_separator(str, separator);
	char	*new = size ? malloc(sizeof(char) * (size + 1)) : NULL;

	if (!(new))
		return (NULL);
	for (int i = 0; i < size; i++)
		new[i] = str[i];
	new[size] = '\0';
	return (new);
}

int		str_len_separator(const char *str, char separator)
{
	int	size = 0;

	if (!(str))
		return (0);
	for (; str[size] && str[size] != separator; size++);
	return (size);
}

int		skip_chars(const char *str, char skip)
{
	int	i = 0;

	if (!(str))
		return (0);
	for (; str[i] && str[i] != skip; i++);
	if (str[i] == skip)
		i++;
	return (i);
}

int		str_eq(const char *s1, const char *s2)
{
	if (len(s1) != len(s2))
		return (ERROR);
	for (int i = 0; s1[i]; i++) {
		if (s1[i] != s2[i])
			return (ERROR);
	}
	return (SUCCESS);
}

int		str_start_eq(const char *s1, const char *s2)
{
	for (int i = 0; s1[i] && s2[i]; i++) {
		if (s1[i] != s2[i])
			return (ERROR);
	}
	return (SUCCESS);
}