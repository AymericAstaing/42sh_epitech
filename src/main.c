/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Program entry
*/

#include	"shell.h"
#include	"printf.h"

int		main(int ac, const char **av, const char **old_env)
{
	shell_t	*shell	= get_shell(ac >= 2 ? av[1] : NULL, old_env);
	int	ret	= C_EXIT_ERROR;

	if (!(shell))
		return (C_EXIT_ERROR);
	ret = shell_loop(shell);
	destroy_shell(&shell);
	return (ret);
}