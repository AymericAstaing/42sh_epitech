/*
** EPITECH PROJECT, 2018
** Env
** File description:
** Init env
*/

#include	"shell.h"

static void	destroy_vars(var_t **vars);

int		init_env(env_t *env)
{
	if (!(env))
		return (ERROR);
	env->name = NULL;
	env->next = NULL;
	env->vars = NULL;
	return (SUCCESS);
}

void		destroy_env(env_t **env)
{
	if (!(env) || !(*env))
		return;
	for (env_t *tmp = *env; tmp; tmp = *env) {
		*env = tmp->next;
		destroy_vars(&tmp->vars);
		check_free((void *)(&tmp->name));
		check_free((void *)(&tmp));
	}
}

static void	destroy_vars(var_t **vars)
{
	if (!(vars) || !(*vars))
		return;
	for (var_t *tmp = *vars; tmp; tmp = *vars) {
		*vars = tmp->next;
		check_free((void *)(&tmp->var));
		check_free((void *)(&tmp));
	}
	*vars = NULL;
}

int		destroy_formated_env(char ***old)
{
	char	**env = old ? *old : NULL;

	if (!(env))
		return (0);
	for (int i = 0; env[i]; i++)
		check_free((void *)(&env[i]));
	check_free((void *)(old));
	return (0);
}