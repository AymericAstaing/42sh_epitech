/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Get shell
*/

#include	"shell.h"

shell_t		*get_shell(const char *path, const char **old_env)
{
	shell_t	*shell	= malloc(sizeof(shell_t));

	if (!(init_shell(shell)))
		return (NULL);
	shell->env	= get_env(old_env);
	check_dir(path);
	return (shell);
}