/*
** EPITECH PROJECT, 2017
** Str copy
** File description:
** Copy string
*/

void		strcp(char *s1, char const *s2)
{
	*s1 = *s2;
	if (s2)
		strcp(s1++, s2++);
}
