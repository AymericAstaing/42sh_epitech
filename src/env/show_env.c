/*
** EPITECH PROJECT, 2018
** Env
** File description:
** Show env
*/

#include	"printf.h"
#include	"shell.h"

static void	display_env(env_t *env);

void		show_env(env_t *list)
{
	for (; list; list = list->next)
		display_env(list);
}

static void	display_env(env_t *env)
{
	my_printf("%s=", env->name);
	for (var_t *var = env->vars; var; var = var->next) {
		if (var->var)
			my_printf("%s", var->var);
		if (var->next)
			my_printf(":");
	}
	my_printf("\n");
}