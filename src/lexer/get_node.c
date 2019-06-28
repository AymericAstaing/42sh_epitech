/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Get node
*/

#include	"shell.h"

static node_t	*clean_exit(node_t **node);

node_t		*get_node(int type, char *str)
{
	node_t	*node = malloc(sizeof(node_t));

	if (!(init_node(node)))
		return (clean_exit(&node));
	node->type = type;
	node->word = str;
	return (node);
}

static node_t	*clean_exit(node_t **node)
{
	destroy_node(node);
	return (NULL);
}

cmd_t		*get_node_cmd(node_t *node)
{
	cmd_t	*cmd = node && node->type == N_CMD && node->data
			? node->data : NULL;

	return (cmd);
}