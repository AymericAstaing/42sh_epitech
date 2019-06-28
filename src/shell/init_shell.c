/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Init shell
*/

#include	"shell.h"

int		init_shell(shell_t *shell)
{
	if (!(shell))
		return (ERROR);
	shell->env		= NULL;
	shell->last_state	= 0;
	shell->last_path	= NULL;
	shell->shell_exit	= -1;
	return (SUCCESS);
}

void		destroy_shell(shell_t **shell)
{	
	destroy_env(&(*shell)->env);
	check_free((void *)(&(*shell)->last_path));
	check_free((void *)(shell));
}