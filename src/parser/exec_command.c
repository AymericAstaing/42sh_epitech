/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Exec command functions
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"printf.h"
#include	"shell.h"

int		get_output_cmd2(cmd_t *cmd, shell_t *shell)
{
	int fd_out;
	int p[FD_TOTAL];
	pid_t pid;
	char **env = get_formated_env(shell);

	if (!(cmd) || !(set_command(cmd, shell)) || pipe(p) == -1
		|| ((pid = fork()) == -1)) {
		destroy_formated_env(&env);
		return (-1);
	}
	if (pid == 0) {
		close2_dup2(p[FD_IN], p[FD_OUT], p[FD_OUT], STDOUT_FILENO);
		custom_exec(cmd, env);
	} else {
		fd_out = close2_dup(p[FD_IN], p[FD_OUT], p[FD_IN]);
		custom_wait_pid(shell);
	}
	destroy_formated_env(&env);
	return (fd_out);
}

int		exec_cmd_input(cmd_t *cmd, int fd_in, shell_t *shell)
{
	int fd_out;
	int p[2];
	pid_t pid;
	char **env = get_formated_env(shell);

	if (!(set_command(cmd, shell)) || pipe(p) == -1 ||
		((pid = fork()) == -1)) {
		destroy_formated_env(&env);
		return (-1);
	}
	if (pid == 0) {
		close2_2dup2(p, fd_in, STDIN_FILENO, STDOUT_FILENO);
		custom_exec(cmd, env);
	} else {
		fd_out = close2_dup(p[FD_IN], p[FD_OUT], p[FD_IN]);
		custom_wait_pid(shell);
	}
	close(fd_in);
	destroy_formated_env(&env);
	return (fd_out);
}

int		exec_cmd(node_t *node, shell_t *shell)
{
	pid_t	pid = 0;
	cmd_t	*cmd = node->data;
	char	**env = get_formated_env(shell);

	if (!(cmd) || !(set_command(cmd, shell)) || !(env)
		|| (pid = fork()) == -1) {
		destroy_formated_env(&env);
		return (-1);
	}
	if (pid == 0) {
		custom_exec(cmd, env);
	} else
		custom_wait_pid(shell);
	destroy_formated_env(&env);
	return (-1);
}

void		print_fd(int fd)
{
	char *buff = NULL;
	size_t n = 0;
	FILE *stream = fdopen(fd, "r");

	if (!(stream))
		return;
	while (getline(&buff, &n, stream) != -1)
		my_printf("%s", buff);
	rewind(stream);
}

void		custom_exec(cmd_t *cmd, char **env)
{
	execve(cmd->av[0], cmd->av, env);
	exit(1);
}