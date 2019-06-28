/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Format env
*/

#include	"printf.h"
#include	"shell.h"

static char	**error_exit(char **);
static int	env_size(env_t *);
static int	get_vars_count(env_t *);
static int	env_cp(char *, env_t *);

char		**get_formated_env(shell_t *shell)
{
	char		**env	= NULL;
	env_t		*t_env	= shell->env;
	int		vars	= get_vars_count(shell->env);
	int		size	= 0;
	int		i	= 0;

	if (!(vars) || !(env = malloc(sizeof(char *) * (vars + 1))))
		return (NULL);
	for (; i < vars && t_env; i++, t_env = t_env->next) {
		size = env_size(t_env);
		if (!(size) || !(env[i] = malloc(sizeof(char) * (size + 1))))
			return (error_exit(env));
		if (!(env_cp(env[i], t_env)))
			return (error_exit(env));
	}
	env[i] = NULL;
	return (env);
}

static char	**error_exit(char **env)
{
	if (env) {
		for (int i = 0; env[i]; i++)
			free(env[i]);
		free(env);
	}
	return (NULL);
}

static int	env_cp(char *env, env_t *t_env)
{
	int	i = 0;

	if (!(env) || !(t_env))
		return (FALSE);
	for (; t_env->name && t_env->name[i]; i++)
		env[i] = t_env->name[i];
	env[i++] = C_NAME_SEPARATOR;
	for (var_t *var = t_env->vars; var; var = var->next) {
		for (int j = 0; var->var && var->var[j]; i++, j++)
			env[i] = var->var[j];
		if (var->next)
			env[i++] = C_VAR_SEPARATOR;
	}
	env[i++] = '\0';
	return (TRUE);
}

static int	get_vars_count(env_t *env)
{
	int	size = 0;

	for (; env; env = env->next, size++);
	return (size);
}

static int	env_size(env_t *env)
{
	int	size = 0;

	if (!(env))
		return (0);
	size += len(env->name) + 1;
	for (var_t *var = env->vars; var; var = var->next, size++)
		size += len(var->var);
	return (size);
}