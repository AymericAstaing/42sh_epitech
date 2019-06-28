/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Build tree
*/

#include	"shell.h"

static int	process_building(node_t *root, const char *input);
static int	get_command(node_t *n[B_TOTAL], const char *input, int *i);
static int	set_links(node_t *root, node_t *n[B_TOTAL]);

node_t		*build_tree(const char *input, shell_t *shell)
{
	node_t	*root	= get_node(N_ROOT, NULL);

	if (!(root))
		return (NULL);
	if (!(process_building(root, input)) || !(check_tree(root, shell)))
		destroy_nodes(&root);
	return (root);
}

static int	process_building(node_t *root, const char *input)
{
	int	i	= 0;
	node_t	*n[B_TOTAL] = { NULL, get_next_node(input, &i), NULL, NULL };
	int	ret	= SUCCESS;

	for (; n[B_NEXT] && ret; n[B_NEXT] = get_next_node(input, &i)) {
		if (n[B_NEXT]->type != N_CMD || !(get_command(n, input, &i))
			|| !(set_links(root, n)))
			ret = ERROR;
	}
	return (ret);
}

static int	get_command(node_t *n[B_TOTAL], const char *input, int *i)
{
	cmd_t	*cmd = get_cmd();
	node_t	*tmp = n[B_NEXT];
	int	ret = SUCCESS;

	for (; ret && tmp; tmp = get_next_node(input, i)) {
		if (tmp->type == N_OP) {
			n[B_OP] = tmp;
			break;
		}
		if (!(add_cmd_arg(cmd, tmp)))
			ret = ERROR;
		if (tmp != n[B_NEXT])
			destroy_node(&tmp);
	}
	n[B_NEXT]->data = cmd;
	return (SUCCESS);
}

static int	set_links(node_t *root, node_t *n[B_TOTAL])
{
	if (n[B_UP])
		n[B_UP]->right = n[B_NEXT];
	if (n[B_OP])
		n[B_OP]->left = n[B_UP] ? n[B_UP] : n[B_NEXT];
	root->left = n[B_OP] ? n[B_OP] : !(root->left) ? n[B_NEXT] : root->left;
	n[B_UP] = n[B_OP];
	n[B_OP] = NULL;
	n[B_PREV] = n[B_NEXT];
	n[B_NEXT] = NULL;
	return (SUCCESS);
}
