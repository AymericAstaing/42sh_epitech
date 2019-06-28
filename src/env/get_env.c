/*
** EPITECH PROJECT, 2018
** Env
** File description:
** Get env
*/

#include	"printf.h"
#include	"shell.h"

static char	*get_name(const char *line, int *i);
static int	add_env_var(env_t *elem, const char *line, int *i);

env_t		*get_env(const char **old_env)
{
	env_t	*env = NULL;

	if (!(old_env))
		return (NULL);
	for (int i = 0; old_env[i]; i++) {
		if (!(add_var(&env, old_env[i])))
			return (NULL);
	}
	return (env);
}

int		add_var(env_t **env, const char *line)
{
	env_t	*elem	= get_env_elem(line);
	env_t	*tmp	= env ? *env : NULL;

	if (!(elem))
		return (ERROR);
	for (; tmp && tmp->next; tmp = tmp->next);
	if (tmp)
		tmp->next = elem;
	else
		*env = elem;
	return (SUCCESS);
}

env_t		*get_env_elem(const char *line)
{
	env_t	*elem	= malloc(sizeof(env_t));
	int	i	= 0;

	if (!(init_env(elem)))
		return (NULL);
	elem->name = get_name(line, &i);
	while (line[i]) {
		add_env_var(elem, line, &i);
	}
	if (i && line[i - 1] == C_VAR_SEPARATOR) {
		i = 0;
		add_env_var(elem, NULL, &i);
	}
	return (elem);
}

static char	*get_name(const char *line, int *i)
{
	char	*name	= str_dup_separator(line + *i, C_NAME_SEPARATOR);

	if (!(name))
		return (NULL);
	*i += len(name);
	*i += skip_chars(line + *i, C_NAME_SEPARATOR);
	return (name);
}

static int	add_env_var(env_t *elem, const char *line, int *i)
{
	var_t	*var	= malloc(sizeof(var_t));
	var_t	*tmp	= elem->vars;

	if (!(var))
		return (ERROR);
	var->next	= NULL;
	var->var	= str_dup_separator(line + *i, C_VAR_SEPARATOR);
	*i += len(var->var);
	*i += skip_chars(line + *i, C_VAR_SEPARATOR);
	for (; tmp && tmp->next; tmp = tmp->next);
	if (tmp)
		tmp->next = var;
	else
		elem->vars = var;
	return (SUCCESS);
}