/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** main tests
*/

#include	"printf.h"
#include	"shell.h"

void		test_strlen_separator(void);
void		test_strtotab(void);

void	flag_h(void)
{
	my_printf("USAGE\n\n\tDESCRIPTION\n\n\tUnit Tests\n\n");
	my_printf(" Write as 2nd argument one of these tests:\n\n\t");
	my_printf("- strlen\n\t- strtotab\n\n");
}

int	main(int ac, char **av)
{
	if (ac > 2)
		return (84);
	if (ac == 1)
		flag_h();
	else if (str_eq(av[1], "strtotab") == 1)
		test_strtotab();
	else if (str_eq(av[1], "strlen") == 1)
		test_strlen_separator();
	return (0);
}
