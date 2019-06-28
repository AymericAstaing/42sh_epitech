/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** File redir functions
*/

#include	"shell.h"
#include	<string.h>
#include	<stdio.h>
#include	<unistd.h>

/*		Operator '>'		*/
int		write_in_file(int fd_in, char *file_name, const char *type,
				shell_t *shell)
{
	FILE	*file = fopen(file_name, type);
	FILE	*stream_in = fdopen(fd_in, "r");
	char	*buff = NULL;
	size_t	n = 0;

	if (!(file)) {
		write(2, file_name, strlen(file_name));
		write(2, ": Permission denied.\n", 21);
		shell->last_state = 1;
		return (ERROR);
	}
	if (!(stream_in))
		return (ERROR);
	while (getline(&buff, &n, stream_in) != -1)
		fprintf(file, "%s", buff);
	shell->last_state = 0;
	fclose(stream_in);
	fclose(file);
	return (SUCCESS);
}
