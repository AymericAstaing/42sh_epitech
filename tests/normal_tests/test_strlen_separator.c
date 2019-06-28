/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** test for strlen with separatos
*/

#include	"printf.h"
#include	"shell.h"

void		test_strlen_separator(void)
{
	char	*str1 = "This Is A Unit Test\n";
	char	*str2 = "This:Is:A:/UnitTest\n";
	char	*str3 = " T h i s I s A U n******itTest\n";
	char	*str4 = "ThisIsAUnitTest\n";
	char	*str5 = "";

	my_printf("\n1- Got [%d]\n\n", str_len_separators(str1, " "));
	my_printf("Expected [%d]\n\n", 4);
	my_printf("\n2- Got [%d]\n\n", str_len_separators(str2, "/"));
	my_printf("Expected [%d]\n\n", 10);
	my_printf("\n3- Got [%d]\n\n", str_len_separators(str3, "*"));
	my_printf("Expected [%d]\n\n", 18);
	my_printf("\n4- Got [%d]\n\n", str_len_separators(str4, " "));
	my_printf("Expected [%d]\n\n", 16);
	my_printf("\n5- Got [%d]\n\n", str_len_separators(str5, ""));
	my_printf("Expected [%d]\n\n", 0);
}
