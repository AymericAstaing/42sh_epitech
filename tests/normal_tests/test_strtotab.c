/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** test str to word tab
*/

#include	"printf.h"
#include	"shell.h"
#include	"shell_common.h"

void		test_strtotab(void)
{
	char *expected = "ThisIsAUnitTestAllCasesAreTried\n";
	char *str = "This Is:A::;;:Unit  ùùù Test:/*All */Cases Are:/Tried";
	char *op = ":;/*ù ";
	char **test = str_to_tab(str, op);

	my_printf("Got:\n");
	for (int i = 0; test[i]; i++)
		my_printf("%s", test[i]);
	my_printf("\n\nExpected:\n%s\n", expected);
}
