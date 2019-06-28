/*
** EPITECH PROJECT, 2018
** Env
** File description:
** Set env
*/

#include	"shell.h"

static int	set_env(shell_t *shell, const char *name,
				const char *s1, const char *s2);
static int	check_var(const char *var, int pos, const char *name);
static int	is_valid(char c);

int		fct_setenv(shell_t *shell, int ac, char **av)
{
	if (ac == 1)
		show_env(shell->env);
	else if (ac == 2 || ac == 3)
		return (set_env(shell, av[0], av[1], (ac == 3 ? av[2] : NULL)));
	else
		return (error(TOO_MANY_ARGS, av[0], NULL));
	return (C_EXIT_SUCCESS);
}

static int	set_env(shell_t *shell, const char *name,
				const char *s1, const char *s2)
{
	char	*with_eq	= str_cat(s1, "=");
	char	*line		= str_cat(with_eq, s2);
	int	ret		= C_EXIT_SUCCESS;

	ret = !(line) ? C_EXIT_ERROR : ret;
	ret = !(ret) ? check_var(s1, 0, name) : ret;
	ret = !(ret) ? check_var(s2, 1, name) : ret;
	check_free((void *)(&with_eq));
	if (ret)
		process_arg(&shell->env, line);
	else
		check_free((void *)(&line));
	return (ret);
}

int		check_var(const char *var, int pos, const char *name)
{
	if (!(var) || (pos == 0 && *var >= '0' && *var <= '9'))
		return (error(LETTER_BEGIN, name, NULL));
	for (int i = 0; var[i]; i++) {
		if (!(is_valid(var[i])))
			return (error(ALPHA_NUM_VAR, name, NULL));
	}
	return (0);
}

static int	is_valid(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || c == '#')
			return (TRUE);
	return (FALSE);
}