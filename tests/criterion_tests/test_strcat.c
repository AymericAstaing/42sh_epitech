/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** test for strcat
*/

#include	<unistd.h>
#include	<criterion/criterion.h>
#include	<criterion/redirect.h>
#include	<fcntl.h>
#include	"shell.h"
#include	"printf.h"
#include	"shell_common.h"

Test(str_cat, without_errors)
{
	const char 	*str1 = "01234";
	const char 	*str2 = "56789";
	char		*got = str_cat(str1, str2);
	char		*expected = "0123456789";

	cr_assert_str_eq(got, expected);
}

Test(str_cat, with_letters_numbers)
{
	const char 	*str1 = "123ThisIsA";
	const char 	*str2 = "UnitTest321";
	char		*got = str_cat(str1, str2);
	char		*expected = "123ThisIsAUnitTest321";

	cr_assert_str_eq(got, expected);
}

Test(str_cat, with_spaces)
{
	const char 	*str1 = "This Is A ";
	const char 	*str2 = "Unit Test";
	char		*got = str_cat(str1, str2);
	char		*expected = "This Is A Unit Test";

	cr_assert_str_eq(got, expected);
}

Test(str_cat, with_tabs)
{
	const char 	*str1 = "This	Is	A	";
	const char 	*str2 = "Unit	Test";
	char		*got = str_cat(str1, str2);
	char		*expected = "This	Is	A	Unit	Test";

	cr_assert_str_eq(got, expected);
}

Test(str_cat, with_all)
{
	const char 	*str1 = "/* This	Is	1A1	";
	const char 	*str2 = "Unit	Test *\\";
	char		*got = str_cat(str1, str2);
	char		*gd = "/* This	Is	1A1	Unit	Test *\\";

	cr_assert_str_eq(got, gd);
}
