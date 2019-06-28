/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Init node
*/

#include	"shell.h"

int		init_node(node_t *node)
{
	if (!(node))
		return (ERROR);
	node->type		= N_NONE;
	node->word		= NULL;
	node->data		= NULL;
	node->res.data		= R_NONE;
	node->res.fd_out	= -1;
	node->left		= NULL;
	node->right		= NULL;
	return (SUCCESS);
}

int		destroy_nodes(node_t **list)
{
	return (destroy_node(list));
}

int		destroy_node(node_t **old)
{
	node_t	*node = old ? *old : NULL;
	cmd_t	*cmd = get_node_cmd(node);

	if (!(node))
		return (0);
	if (cmd)
		destroy_cmd(&cmd);
	destroy_node(&node->left);
	destroy_node(&node->right);
	check_free((void *)(&node->word));
	check_free((void *)(old));
	return (0);
}