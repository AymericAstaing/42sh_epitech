/*
** EPITECH PROJECT, 2018
** Commands
** File description:
** Exit builtin
*/

#include	"shell.h"

int		fct_exit(shell_t *shell, int ac, char **av)
{
	if (ac == 1)
		shell->shell_exit = shell->last_state;
	else if (ac == 2)
		shell->shell_exit = get_nb(av[1]);
	else
		return (error(EXPR_SYNTAX, av[0], NULL));
	return (shell->shell_exit);
}