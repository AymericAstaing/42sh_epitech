/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** Set command
*/

#include	"shell_commands.h"

static int	check_base_commands(cmd_t *, shell_t *);
static int	check_path(cmd_t *, shell_t *);
static int	check_command_path(cmd_t *, var_t *);

int		set_command(cmd_t *cmd, shell_t *shell)
{
	if (!(cmd))
		return (FALSE);
	if (check_base_commands(cmd, shell))
		return (FALSE);
	if (!(check_path(cmd, shell)) && (exists(cmd->av[0])
		&& !(has_op(cmd->av[0], C_FILE_SEPARATOR)))) {
		shell->last_state = error(CMD_NOT_FOUND,
			cmd->av ? cmd->av[0] : NULL, NULL);
		return (FALSE);
	}
	return (TRUE);
}

static int	check_base_commands(cmd_t *command, shell_t *shell)
{
	for (int i = 0; i < C_BASE_CMD_NB; i++) {
		if (str_eq(C_BASE_CMD[i].command, command->av[0])) {
			exec_base_command(&C_BASE_CMD[i], command, shell);
			return (SUCCESS);
		}
	}
	return (ERROR);
}

static int	check_path(cmd_t *command, shell_t *shell)
{
	env_t		*path = in_env(shell->env, C_PATH, TRUE);

	if (!(path))
		return (ERROR);
	for (var_t *tmp = path->vars; tmp; tmp = tmp->next) {
		if (check_command_path(command, tmp))
			return (SUCCESS);
	}
	return (ERROR);
}

static int	check_command_path(cmd_t *command, var_t *dir)
{
	char	*tmp	= str_cat(dir->var, C_FILE_SEPARATOR);
	char	*res	= str_cat(tmp, command->av[0]);

	if (tmp)
		free(tmp);
	if (exists(res)) {
		if (command->av[0])
			free(command->av[0]);
		command->av[0] = res;
		return (TRUE);
	}
	free(res);
	return (FALSE);
}
