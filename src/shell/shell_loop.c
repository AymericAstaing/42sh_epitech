/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Shell loop
*/

#include	<signal.h>
#include	"get_next_line.h"
#include	"printf.h"
#include	"shell.h"

int		shell_loop(shell_t *shell)
{
	int	ret = ERROR;

	signal(SIGINT, ctrl_c_handler);
	do {
		ret = shell_prompt(shell);
	} while (shell->shell_exit == -1 && ret == SUCCESS);
	if (ret == STOP)
		my_printf(C_EXIT_MSG);
	if (shell->shell_exit != -1)
		return (shell->shell_exit);
	return (ret == STOP ? shell->last_state : C_EXIT_ERROR);
}

void		ctrl_c_handler(int sig)
{
	signal(sig, ctrl_c_handler);
	my_printf("\n");
}