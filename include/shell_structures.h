/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Structures header
*/

#ifndef SHELL_STRUCTURES_H_
	#define SHELL_STRUCTURES_H_

typedef	struct base_command_s	base_command_t;
typedef	struct cmd_s		cmd_t;
typedef	struct result_s		result_t;
typedef	struct node_s		node_t;
typedef	struct var_s		var_t;
typedef	struct env_s		env_t;
typedef	struct shell_s		shell_t;

struct base_command_s {
	const char	*command;
	int		(*fct)(shell_t *, int, char **);
};

struct	cmd_s {
	int	ac;
	char	**av;
	int	fd[FD_TOTAL];
};

struct	result_s {
	int	data;
	int	fd_out;
};

struct	node_s {
	int		type;
	char		*word;
	void		*data;
	result_t	res;
	node_t		*left;
	node_t		*right;
};

struct	var_s {
	var_t		*next;
	char		*var;
};

struct	env_s {
	env_t		*next;
	char		*name;
	var_t		*vars;
};

struct	shell_s {
	env_t		*env;
	int		last_state;
	char		*last_path;
	int		shell_exit;
};

#endif /* !SHELL_STRUCTURES_H_ */
