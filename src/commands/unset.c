/*
** EPITECH PROJECT, 2018
** Env
** File description:
** Unset
*/

#include	"shell.h"

static void	delete_env(env_t **env, env_t *to_delete);

int		fct_unset(shell_t *shell, int ac, char **av)
{
	env_t	*tmp = NULL;

	for (int i = 1; i < ac; i++) {
		tmp = in_env(shell->env, av[i], TRUE);
		if (tmp)
			delete_env(&shell->env, tmp);
	}
	return (C_EXIT_SUCCESS);
}

static void	delete_env(env_t **env, env_t *to_delete)
{
	env_t	*tmp = *env;

	if (*env == to_delete) {
		*env = to_delete->next;
	} else {
		for (; tmp && tmp->next != to_delete; tmp = tmp->next);
		tmp->next = to_delete->next;
	}
	to_delete->next = NULL;
	destroy_env(&to_delete);
}