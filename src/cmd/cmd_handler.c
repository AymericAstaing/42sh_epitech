/*
** EPITECH PROJECT, 2018
** Cmd
** File description:
** Command handler
*/

#include	"shell.h"

cmd_t		*get_cmd(void)
{
	cmd_t	*cmd = malloc(sizeof(cmd_t));

	if (!(init_cmd(cmd)))
		return (NULL);
	return (cmd);
}

int		init_cmd(cmd_t *cmd)
{
	if (!(cmd))
		return (ERROR);
	cmd->ac = 0;
	cmd->av = NULL;
	cmd->fd[FD_IN] = -1;
	cmd->fd[FD_OUT] = -1;
	return (SUCCESS);
}

int		destroy_cmd(cmd_t **old)
{
	cmd_t	*cmd = old ? *old : NULL;

	if (!(cmd))
		return (0);
	for (int i = 0; i < cmd->ac; i++)
		check_free((void *)(&cmd->av[i]));
	check_free((void *)(&cmd->av));
	check_free((void *)(&cmd));
	return (0);
}

int		add_cmd_arg(cmd_t *cmd, node_t *node)
{
	char *arg = node && cmd ? str_dup_separator(node->word, '\0') : NULL;

	if (!(arg))
		return (ERROR);
	cmd->ac++;
	add_elem_to_tab(&cmd->av, cmd->ac, arg);
	return (SUCCESS);
}