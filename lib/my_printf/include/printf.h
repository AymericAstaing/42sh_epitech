/*
** EPITECH PROJECT, 2017
** Printf
** File description:
** Printf main header
*/

#ifndef		PRINTF_H_
#define		PRINTF_H_

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdarg.h>

static const char	C_NULL[]	= "(null)";
static const char	C_NIL[]		= "(nil)";

static const char	C_BI[]		= "01";
static const char	C_OCT[]		= "01234567";
static const char	C_DEC[]		= "0123456789";
static const char	C_HEX[]		= "0123456789abcdef";
static const char	C_MHEX[]	= "0123456789ABCDEF";

#define		C_FLAGS		32

typedef		struct flag {
	int	(*fct)(va_list *);
	char	*flag;
}		flag_t;

int		my_printf(const char *, ...);
int		display_arg(char const * const, int *, va_list *);

/*	Utils		*/
int		len(char const * const);
void		rev(char *);
void		strcp(char *, char const *);

/*	Display		*/
int		put_char(char const);
int		put_str(char const * const);
int		put_fstr(char const * const);
int		put_long(long);
int		put_ulong(unsigned long);
int		put_double(long double);
int		put_base(unsigned long, char const *);
int		put_ptr(void const *);

/*	Flags		*/
int		f_char(va_list *);
int		f_str(va_list *);
int		f_fstr(va_list *);
int		f_short(va_list *);
int		f_int(va_list *);
int		f_long(va_list *);
int		f_ushort(va_list *);
int		f_uint(va_list *);
int		f_ulong(va_list *);
int		f_double(va_list *);
int		f_ldouble(va_list *);
int		f_ptr(va_list *);
int		f_bi(va_list *);
int		f_lbi(va_list *);
int		f_oct(va_list *);
int		f_loct(va_list *);
int		f_dec(va_list *);
int		f_ldec(va_list *);
int		f_hex(va_list *);
int		f_lhex(va_list *);
int		f_mhex(va_list *);
int		f_mlhex(va_list *);
int		f_percent(va_list *);

#endif
