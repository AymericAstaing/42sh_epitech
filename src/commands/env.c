/*
** EPITECH PROJECT, 2018
** Env
** File description:
** Set env
*/

#include	"shell.h"

static int	check_arg(const char *arg);
static int	change_var(env_t **env, env_t *tmp, const char *arg);

int		fct_env(shell_t *shell, int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		if (!(check_arg(av[i])))
			return (error(NO_FILE_DIRECTORY, av[0], av[i]));
	}
	for (int i = 1; i < ac; i++) {
		if (!(process_arg(&shell->env, av[i])))
			return (C_EXIT_ERROR);
	}
	show_env(shell->env);
	return (C_EXIT_SUCCESS);
}

env_t		*in_env(env_t *env, const char *arg, int f_eq)
{
	for (; env; env = env->next) {
		if (f_eq && str_eq(env->name, arg))
			return (env);
		else if (!(f_eq) && str_start_eq(env->name, arg))
			return (env);
	}
	return (NULL);
}

int		process_arg(env_t **env, const char *arg)
{
	env_t	*tmp = in_env(*env, arg, FALSE);

	if (tmp)
		return (change_var(env, tmp, arg));
	else
		return (add_var(env, arg));
}

static int	check_arg(const char *arg)
{
	if (!(arg))
		return (ERROR);
	for (int i = 0; arg[i]; i++)
		if (arg[i] == C_NAME_SEPARATOR)
			return (SUCCESS);
	return (ERROR);
}

static int	change_var(env_t **env, env_t *tmp, const char *arg)
{
	env_t	*elem = get_env_elem(arg);
	env_t	*prev = *env;

	elem->next = tmp->next;
	if (tmp == *env)
		*env = elem;
	else {
		for (; prev && prev->next != tmp; prev = prev->next);
		if (prev->next == tmp)
			prev->next = elem;
	}
	tmp->next = NULL;
	destroy_env(&tmp);
	return (SUCCESS);
}