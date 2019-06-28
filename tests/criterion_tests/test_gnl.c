/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** test
*/

#include	"get_next_line.h"
#include	<criterion/criterion.h>
#include	<criterion/redirect.h>
#include	<fcntl.h>
#include	<unistd.h>

Test(get_next_line, read_line)
{
	int fd = -1;
	char *expected = "We are going to test the get_next_line function";
	char *got;

	fd = open("test_gnl.txt", O_RDONLY);
	got = get_next_line(fd);
	cr_assert_str_eq(got, expected);
}
