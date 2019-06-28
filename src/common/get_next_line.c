/*
** EPITECH PROJECT, 2017
** GNL
** File description:
** Get next line
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"get_next_line.h"

static int	has_line(buffer_t *);
static int	read_file(buffer_t **, int);
static int	str_to_list(buffer_t **, char *, int);
static char	*convert_buffer(buffer_t **);

char		*get_next_line(int fd)
{
	static buffer_t	*buffer;

	if (fd == -1)
		return (NULL);
	while (!(has_line(buffer)))
		if (read_file(&buffer, fd))
			break;
	return (convert_buffer(&buffer));
}

static int	has_line(buffer_t *buffer)
{
	for (int i = 0; buffer; buffer = buffer->next, i++)
		if (buffer->data == '\0')
			return (i + 1);
	return (FALSE);
}

static int	read_file(buffer_t **buffer, int fd)
{
	char	*tmp = malloc(sizeof(char) * READ_SIZE);
	int	size;
	int	ret = ERROR;

	if (!(tmp) || (size = read(fd, tmp, READ_SIZE)) <= 0 ||
			!(str_to_list(buffer, tmp, size)) ||
			size != READ_SIZE)
		ret = SUCCESS;
	if (tmp)
		free(tmp);
	return (ret);
}

static int	str_to_list(buffer_t **buffer, char *str, int size)
{
	buffer_t	*elem = NULL;
	buffer_t	*tmp = NULL;
	int		i = size - 1;

	while (i >= 0) {
		if (!(elem = malloc(sizeof(buffer_t))))
			return (ERROR);
		elem->data = str[i] == '\n' ? '\0' : str[i];
		elem->next = tmp;
		tmp = elem;
		i--;
	}
	for (elem = *buffer; elem && elem->next; elem = elem->next);
	if (elem)
		elem->next = tmp;
	else
		*buffer = tmp;
	return (SUCCESS);
}

static char	*convert_buffer(buffer_t **buffer)
{
	buffer_t	*tmp = *buffer;
	int		size = has_line(*buffer);
	char		*res = NULL;
	int		i = 0;

	if (!(tmp) || !(size) || !(res = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	for (tmp = *buffer; tmp && i < size; tmp = *buffer, i++) {
		res[i] = tmp->data;
		*buffer = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	return (res);
}
