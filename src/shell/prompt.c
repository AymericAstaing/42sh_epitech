/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Shell prompt
*/

#include	"get_next_line.h"
#include	"printf.h"
#include	"shell.h"

static int	parse(const char *input, shell_t *shell);

int		shell_prompt(shell_t *shell)
{
	char	*input = NULL;

	get_values(shell);
	input = get_next_line(0);
	if (!(input))
		return (STOP);
	if (!(parse(input, shell)))
		return (check_free((void *)(&input)));
	check_free((void *)(&input));
	return (SUCCESS);
}

static int	parse(const char *input, shell_t *shell)
{
	node_t	*tree = build_tree(input, shell);

	if (!(tree))
		return (SUCCESS);
	exec_tree(tree, shell);
	destroy_nodes(&tree);
	return (SUCCESS);
}