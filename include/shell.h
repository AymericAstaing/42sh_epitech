/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Shell header
*/

#ifndef SHELL_H_
	#define SHELL_H_

#include	<stdlib.h>
#include	"shell_common.h"
#include	"shell_vars.h"
#include	"shell_structures.h"

#define		IS_DIGIT(c)		(c >= '0' && c <= '9')

/*		Shell		*/
int		init_shell(shell_t *);
void		destroy_shell(shell_t **);
int		shell_loop(shell_t *);
int		shell_prompt(shell_t *);
shell_t		*get_shell(const char *, const char **);
void		ctrl_c_handler(int);

/*		Lexer		*/
/*	Nodes		*/
int		init_node(node_t *);
int		destroy_nodes(node_t **);
int		destroy_node(node_t **);
node_t		*get_node(int, char *);
cmd_t		*get_node_cmd(node_t *);
node_t		*get_next_node(const char *, int *);
int		identify_type(const char *);
int		skip_space(const char *, int *);
void		show_node(node_t *);
void		show_tree(node_t *);
/*	Build		*/
node_t		*build_tree(const char *, shell_t *);
int		check_tree(node_t *, shell_t *);
/*	Lexer strings	*/
char		*get_word(const char *, int *);

/*		Prompt		*/
void		get_values(shell_t *);

/*		Common		*/
/*	Checks		*/
int		check_free(void **);
/*	String		*/
int		str_len_separator(const char *, char);
int		str_len_separators(const char *, const char *);
char		*str_dup_separator(const char *, char);
char		*str_dup_separators(const char *, const char *);
int		str_eq(const char *, const char *);
int		str_start_eq(const char *, const char *);
int		skip_chars(const char *, char);
int		is_op(char, const char *);
void		skip_op(const char *, int *, const char *);
int		has_op(const char *, const char *);
char		*str_cat(const char *, const char *);
int		str_remove_op(char **, const char *);
int		mult_str_start_eq(const char *, const char **);
int		add_elem_to_tab(char ***, int, char *);
int		get_op_number(const char *, const char *);
char		*nstr_dup(const char *, int);
/*	Tab		*/
char		**str_to_tab(const char *, const char *);
int		destroy_tab(char ***);
/*	Error		*/
int		error(int, const char *, const char *);
/*	Directories	*/
char		*get_cwd(int);
char		*get_cwd_name(char *);
int		check_dir(const char *);
/*	Numbers		*/
int		get_nb(const char *);

/*		Cmd		*/
cmd_t		*get_cmd(void);
int		init_cmd(cmd_t *);
int		destroy_cmd(cmd_t **);
int		add_cmd_arg(cmd_t *, node_t *);

/*		Env		*/
/*	Env structure	*/
int		init_env(env_t *);
void		destroy_env(env_t **);
env_t		*get_env(const char **);
int		add_var(env_t **, const char *);
env_t		*get_env_elem(const char *);
int		destroy_formated_env(char ***);
/*	Env utils	*/
void		show_env(env_t *);
env_t		*in_env(env_t *, const char *, int);
char		**get_formated_env(shell_t *);
int		process_arg(env_t **, const char *);

/*		Builtins	*/
int		fct_cd(shell_t *, int, char **);
int		fct_env(shell_t *, int, char **);
int		fct_unset(shell_t *, int, char **);
int		fct_exit(shell_t *, int, char **);
int		fct_setenv(shell_t *, int, char **);

/*		Parser		*/
/*	Operator manager	*/
void		switch_op(node_t *, shell_t *);
int		op_pipe(node_t *, shell_t *);
int		op_sep(node_t *, shell_t *);
int		exec_sep_cmd(node_t *, shell_t *);
int		op_amp_2(node_t *, shell_t *);
int		op_redir_out_2(node_t *, shell_t *);
int		op_redir_out(node_t *, shell_t *);
int		op_redir_in(node_t *, shell_t *);
int		op_pipe2(node_t *, shell_t *);
/*	Execute command		*/
int		exec_cmd(node_t *, shell_t *);
int		exec_cmd_input(cmd_t *, int, shell_t *);
int		get_output_cmd2(cmd_t *, shell_t *);
void		print_fd(int);
int		exec_tree(node_t *, shell_t *);
int		set_command(cmd_t *, shell_t *);
int		exists(char *);
int		exec_base_command(const base_command_t *, cmd_t *, shell_t *);
int		close2_dup(int, int, int);
int		close2_dup2(int, int, int, int);
int		close2_2dup2(int [FD_TOTAL], int, int, int);
void		custom_exec(cmd_t *, char **);
void		custom_wait_pid(shell_t *);
/*	File manager		*/
int		write_in_file(int, char *, const char *, shell_t *);

#endif /* !SHELL_H_ */
