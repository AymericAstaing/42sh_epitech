/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tests get_nbr
*/

#include	<unistd.h>
#include	<criterion/criterion.h>
#include	<criterion/redirect.h>
#include	<fcntl.h>
#include	"shell.h"

Test(get_nb, without_errors)
{
	int		expected = 123456;
	const char 	*got = "123456\n";
	int		new = get_nb(got);

	cr_assert_eq(new, expected);
}

Test(get_nb, with_NULL)
{
	int		expected = 0;
	const char 	*got = NULL;
	int		new = get_nb(got);

	cr_assert_eq(new, expected);
}

Test(get_nb, with_empty)
{
	int		expected = 0;
	const char 	*got = "";
	int		new = get_nb(got);

	cr_assert_eq(new, expected);
}

Test(get_nb, with_letters)
{
	int		expected = 0;
	const char 	*got = "ThisIsAUnitTest";
	int		new = get_nb(got);

	cr_assert_eq(new, expected);
}

Test(get_nb, with_letters_and_numbers)
{
	int		expected = 12345;
	const char 	*got = "TestNumber12345";
	int		new = get_nb(got);

	cr_assert_eq(new, expected);
}
