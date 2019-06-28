/*
** EPITECH PROJECT, 2017
** Len
** File description:
** Return the len of a string
*/

int		len(char const * const str)
{
	int	i = 0;

	if (!(str))
		return (0);
	for (; str[i]; i++);
	return (i);
}
