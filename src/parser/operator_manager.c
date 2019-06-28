/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Operator manager functions
*/


#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"shell_lexer_vars.h"

int		exec_sep_cmd(node_t *node, shell_t *shell)
{
	int	fd_out = -1;

	if (!(node))
		return (fd_out);
	if (node->type == N_OP) {
		switch_op(node, shell);
		fd_out = node->res.fd_out;
	} else if (node->type == N_CMD)
		fd_out = get_output_cmd2(node->data, shell);
	return (fd_out);
}

int		op_sep(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*left = node->left;
	node_t	*right = node->right;

	fd_out = exec_sep_cmd(left, shell);
	print_fd(fd_out);
	fd_out = exec_sep_cmd(right, shell);
	return (fd_out);
}

int		op_pipe(node_t *node, shell_t *shell)
{
	int	fd_out = -1;
	node_t	*left = node->left;

	if (left->type == N_CMD)
		fd_out = get_output_cmd2(left->data, shell);
	else if (left->type == N_OP) {
		switch_op(left, shell);
		fd_out = left->res.fd_out;
	}
	fd_out = exec_cmd_input((node->right->data), fd_out, shell);
	return (fd_out);
}

void		switch_op(node_t *node, shell_t *shell)
{
	int	res = -1;
	int	(*op[C_OP_NB])(node_t *, shell_t *) = {
		op_pipe, op_redir_in, op_redir_out, op_redir_out_2,
		op_pipe2, op_amp_2, op_sep
	};

	for (int i = 0; i < C_OP_NB; i++) {
		if (str_eq(node->word, C_OPERATORS[i])) {
			res = op[i](node, shell);
			break;
		}
	}
	destroy_node(&node->left);
	destroy_node(&node->right);
	node->res.fd_out = res;
}

int		exec_tree(node_t *root, shell_t *shell)
{
	if (!(root) || !(root->left))
		return (SUCCESS);
	if (root->left->type == N_OP)
		switch_op(root->left, shell);
	else if (root->left->type == N_CMD)
		exec_cmd(root->left, shell);
	print_fd(root->left->res.fd_out);
	close(root->left->res.fd_out);
	return (SUCCESS);
}