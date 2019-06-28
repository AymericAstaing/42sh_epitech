/*
** EPITECH PROJECT, 2018
** Commands
** File description:
** CD
*/

#include	"shell.h"
#include	<unistd.h>
#include	"printf.h"

static int	change_directory(shell_t *shell, const char *var);

int		fct_cd(shell_t *shell, int ac, char **av)
{
	env_t	*home = NULL;

	if (ac == 1) {
		home = in_env(shell->env, "HOME", TRUE);
		if (home && home->vars && home->vars->var)
			return (change_directory(shell, home->vars->var));
	} else if (ac == 2) {
		return (change_directory(shell, av[1]));
	} else
		return (error(TOO_MANY_ARGS, av[0], NULL));
	return (C_EXIT_SUCCESS);
}

static int	change_directory(shell_t *shell, const char *var)
{
	char	*cwd = NULL;

	if (str_eq(var, C_LESS_ARG) && !(str_eq(shell->last_path, C_LESS_ARG)))
		return (change_directory(shell, shell->last_path));
	cwd = get_cwd(1);
	if (check_dir(var)) {
		check_free((void *)(&shell->last_path));
		shell->last_path = cwd;
		return (C_EXIT_SUCCESS);
	}
	check_free((void *)(&cwd));
	return (error(NO_FILE_DIRECTORY_2, NULL, var));
}

char		*get_cwd(int try_count)
{
	char	*path = NULL;
	char	*res = NULL;

	if (try_count <= 0 || try_count >= C_MAX_TRY_CWD)
		return (NULL);
	path = malloc(sizeof(char) * C_CWD_BUFFER * try_count);
	if (!(path))
		return (NULL);
	if (!(getcwd(path, C_CWD_BUFFER * try_count))) {
		check_free((void *)(&path));
		return (get_cwd(try_count + 1));
	}
	res = str_dup_separator(path, '\0');
	check_free((void *)(&path));
	return (res);
}

char		*get_cwd_name(char *cwd)
{
	int	size = len(cwd);

	if (!(size))
		return (NULL);
	for (size -= 2; size > 0 && cwd[size] != C_FILE_SEPARATOR_CHAR; size--);
	return (cwd + size + 1);
}

int		check_dir(const char *dir)
{
	if (dir && chdir(dir) == 0)
		return (SUCCESS);
	return (ERROR);
}