/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Exec command utils
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	"printf.h"
#include	"shell.h"

int		close2_dup(int fd1, int fd2, int to_dup)
{
	int	out = -1;

	out = dup(to_dup);
	close(fd1);
	close(fd2);
	return (out);
}

int		close2_dup2(int fd1, int fd2, int to_dup, int to_dup2)
{
	int	out = -1;

	close(fd1);
	out = dup2(to_dup, to_dup2);
	close(fd2);
	return (out);
}

int		close2_2dup2(int p[FD_TOTAL], int fd1, int fd2, int fd3)
{
	int	out = -1;

	close(p[FD_IN]);
	dup2(fd1, fd2);
	out = dup2(p[FD_OUT], fd3);
	close(p[FD_OUT]);
	return (out);
}

void		custom_wait_pid(shell_t *shell)
{
	waitpid(-1, &shell->last_state, 0);
	if (shell->last_state == C_SEGFAULT_CODE)
		my_printf(C_SEGFAULT);
	else if (shell->last_state == C_FLOAT_CODE)
		my_printf(C_FLOAT_EXCEPTION);
}