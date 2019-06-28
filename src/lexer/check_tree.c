/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Check tree
*/

#include	"shell.h"

static int	check_pipes(node_t *tmp, shell_t *shell);
static int	is_pipe(node_t *node);
static int	is_redirection(node_t *node, int direction);
static int	check_ops(node_t *tmp, shell_t *shell);

int		check_tree(node_t *root, shell_t *shell)
{
	if (!(root) || !(check_pipes(root, shell))
		|| !(check_ops(root, shell)))
		return (ERROR);
	return (SUCCESS);
}

static int	check_ops(node_t *tmp, shell_t *shell)
{
	while (tmp) {
		if (tmp->type == N_OP && !(str_eq(tmp->word, C_SEPARATOR))
			&& (!(tmp->left) || !(tmp->right))) {
			shell->last_state = error(NULL_CMD, NULL, NULL);
			return (ERROR);
		}
		tmp = tmp->left;
	}
	return (SUCCESS);
}

static int	check_pipes(node_t *tmp, shell_t *shell)
{
	int	state	= SUCCESS;

	while (tmp && state) {
		if (is_pipe(tmp) && is_redirection(tmp->left, D_RIGHT)) {
			state = ERROR;
			shell->last_state = error(AMBIGOUS_INPUT, NULL, NULL);
		}
		else if (is_redirection(tmp, D_LEFT) && is_pipe(tmp->left)) {
			state = ERROR;
			shell->last_state = error(AMBIGOUS_OUTPUT, NULL, NULL);
		}
		tmp = tmp->left;
	}
	return (state);
}

static int	is_pipe(node_t *node)
{
	if (node && node->type == N_OP && str_eq(node->word, C_PIPE_CHAR))
		return (SUCCESS);
	return (ERROR);
}

static int	is_redirection(node_t *node, int direction)
{
	const char *str = direction == D_LEFT ? C_REDIRECT_LEFT
			: C_REDIRECT_RIGHT;

	if (node && node->type == N_OP && str_eq(node->word, str))
		return (SUCCESS);
	return (ERROR);
}