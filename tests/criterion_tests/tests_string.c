/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** test str equal functions
*/

#include	<unistd.h>
#include	<criterion/criterion.h>
#include	<criterion/redirect.h>
#include	<fcntl.h>

Test(str_eq, without_errors)
{
	const char 	*str1 = "123456";
	const char 	*str2 = "123456";
	int		got = str_eq(str1, str2);
	int		expected = 1;

	cr_assert_eq(got, expected);
}

Test(str_eq, with_letters)
{
	const char 	*str1 = "ThisIsAUnitTest";
	const char 	*str2 = "ThisIsAUnitTest";
	int		got = str_eq(str1, str2);
	int		expected = 1;

	cr_assert_eq(got, expected);
}

Test(str_eq, with_both)
{
	const char 	*str1 = "ThisIsAUnitTest123456";
	const char 	*str2 = "ThisIsAUnitTest123456";
	int		got = str_eq(str1, str2);
	int		expected = 1;

	cr_assert_eq(got, expected);
}

Test(str_eq, with_allchars)
{
	const char 	*str1 = "/* 123 ThisIsAUnitTest 321 *\\";
	const char 	*str2 = "/* 123 ThisIsAUnitTest 321 *\\";
	int		got = str_eq(str1, str2);
	int		expected = 1;

	cr_assert_eq(got, expected);
}

Test(str_eq, with_empty)
{
	const char 	*str1 = "";
	const char 	*str2 = "";
	int		got = str_eq(str1, str2);
	int		expected = 1;

	cr_assert_eq(got, expected);
}
