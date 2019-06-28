/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Operator manager 2
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"shell.h"

int		op_pipe2(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*left = node->left;
	node_t	*right = node->right;

	fd_out = exec_sep_cmd(left, shell);
	if (shell->last_state != 0)
		fd_out = exec_sep_cmd(right, shell);
	return (fd_out);
}

int		op_redir_in(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*right = node->right;
	node_t	*left = node->left;
	int	fd_file = open(right->word, O_RDONLY);

	if (left->type == N_CMD && fd_file != -1) {
		fd_out = exec_cmd_input(left->data, fd_file, shell);
		close(fd_file);
	}
	return (fd_out);
}

int		op_redir_out(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*left = node->left;
	node_t	*right = node->right;

	if (left->type == N_CMD) {
		fd_out = get_output_cmd2(left->data, shell);
		write_in_file(fd_out, right->word, "w", shell);
	} else if (left->type == N_OP) {
		switch_op(left, shell);
		fd_out = left->res.fd_out;
		write_in_file(fd_out, right->word, "w", shell);
	}
	return (fd_out);
}

int		op_redir_out_2(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*left = node->left;
	node_t	*right = node->right;

	if (left->type == N_CMD) {
		fd_out = get_output_cmd2(left->data, shell);
		write_in_file(fd_out, right->word, "a", shell);
	} else if (left->type == N_OP) {
		switch_op(left, shell);
		fd_out = left->res.fd_out;
		write_in_file(fd_out, right->word, "a", shell);
	}
	return (fd_out);
}

int		op_amp_2(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*left = node->left;
	node_t	*right = node->right;

	exec_sep_cmd(left, shell);
	if (shell->last_state == 0)
		fd_out = exec_sep_cmd(right, shell);
	return (fd_out);
}