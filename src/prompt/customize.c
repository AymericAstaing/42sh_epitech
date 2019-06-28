/*
** EPITECH PROJECT, 2017
** Prompt
** File description:
** function that customizes our prompt
*/

#include	"printf.h"
#include	"shell.h"

void		color(const char *param)
{
	my_printf("\033[%sm", param);
}

void		get_values(shell_t *data)
{
	char	*cwd = get_cwd(1);

	if (data->last_state == 0) {
		color(GREEN);
		my_printf("42sh ");
	} else {
		color(RED);
		my_printf("42sh ");
	}
	color(SKY_BLUE);
	my_printf("%s ", get_cwd_name(cwd));
	free(cwd);
	color(RESET);
}
