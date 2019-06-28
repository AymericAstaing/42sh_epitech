/*
** EPITECH PROJECT, 2018
** Lexer
** File description:
** Show node
*/

#include	"printf.h"
#include	"shell.h"

void		show_node(node_t *node)
{
	static const char	*types[N_TOTAL] = {
		"None", "Root", "Command", "Operator"
	};

	if (!(node))
		return;
	my_printf("Node\t%s\t:\t%s\n", types[node->type], node->word);
}

void		show_tree(node_t *root)
{
	cmd_t	*cmd = get_node_cmd(root);

	if (!(root))
		return;
	my_printf("\t\t\'%s\'", root->word);
	if (root->type == N_CMD && root->data) {
		my_printf("\t{ ac = %d } { av = ", cmd->ac);
		for (int i = 0; cmd->av[i]; i++)
			my_printf("%s%s", cmd->av[i], cmd->av[i + 1]
					? " | " : " }");
	}
	my_printf("\n");
	if (root->left)
		my_printf("Left: \'%s\'", root->left->word);
	if (root->right)
		my_printf("\t\tRight: \'%s\'", root->right->word);
	my_printf("\n");
	show_tree(root->left);
	show_tree(root->right);
}