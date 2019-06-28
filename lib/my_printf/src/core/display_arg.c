/*
** EPITECH PROJECT, 2017
** Argument
** File description:
** Display arg
*/

#include	"printf.h"

static int	flag_cmp(char const * const, int *, char const * const);
static flag_t	*get_flags(void);

int		display_arg(char const * const format, int *id, va_list *list)
{
	flag_t	*flags = get_flags();
	int	space = 0;

	for (int i = 0; i < C_FLAGS; i++) {
		space = flag_cmp(format, id, flags[i].flag);
		if (space)
			return (flags[i].fct(list) + (space - 1));
	}
	(*id)++;
	return (0);
}

static int	flag_cmp(char const * const format, int *id,
				char const * const flag)
{
	int	i = *id + 1;
	int	space = 0;

	if (!(format[i]))
		return (0);
	for (int j = 0; flag[j]; i++) {
		if (format[i] != ' ' && format[i] != flag[j++])
			return (0);
		if (format[i] == ' ')
			space = 1;
	}
	*id = i;
	if (space)
		put_char(' ');
	return (1 + space);
}

static flag_t	*get_flags(void)
{
	static flag_t	flags[C_FLAGS] = {
		{ f_char,	"c"	}, { f_str,	"s"	},
		{ f_fstr,	"S"	}, { f_int,	"d"	},
		{ f_int,	"i"	}, { f_int,	"hd"	},
		{ f_int,	"hi"	}, { f_long,	"ld"	},
		{ f_long,	"li"	}, { f_uint,	"hu"	},
		{ f_uint,	"u"	}, { f_ulong,	"lu"	},
		{ f_ptr,	"p"	}, { f_bi,	"hb"	},
		{ f_bi,		"b"	}, { f_lbi,	"lb"	},
		{ f_oct,	"ho"	}, { f_loct,	"o"	},
		{ f_loct,	"lo"	}, { f_dec,	"hu"	},
		{ f_dec,	"u"	}, { f_ldec,	"lu"	},
		{ f_hex,	"hx"	}, { f_hex,	"x"	},
		{ f_lhex,	"lx"	}, { f_mhex,	"hX"	},
		{ f_mhex,	"X"	}, { f_mlhex,	"lX"	},
		{ f_double,	"hf"	}, { f_double,	"f"	},
		{ f_ldouble,	"Lf"	}, { f_percent,	"%"	}
	};

	return (flags);
}
