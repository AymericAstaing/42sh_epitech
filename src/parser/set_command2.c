/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Set command 2
*/

#include	<sys/stat.h>
#include	"printf.h"
#include	"shell_commands.h"

int		exists(char *path)
{
	struct stat	buff;

	if (stat(path, &buff))
		return (FALSE);
	return (TRUE);
}

int		exec_base_command(const base_command_t *b_cmd, cmd_t *cmd,
					shell_t *shell)
{
	if (!(b_cmd->fct))
		return (ERROR);
	shell->last_state = b_cmd->fct(shell, cmd->ac, cmd->av);
	return (SUCCESS);
}