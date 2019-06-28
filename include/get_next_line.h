/*
** EPITECH PROJECT, 2017
** Get next line
** File description:
** Get next line header
*/

#ifndef		GNL_H_
#define		GNL_H_

#ifndef READ_SIZE
	#define READ_SIZE 256
#endif

typedef		struct buffer {
	char		data;
	struct buffer	*next;
}		buffer_t;

char		*get_next_line(int);

#ifndef		ENUM_RET_ERR
	#define		ENUM_RET_ERR

enum		ret_err {
	ERROR = 0,
	SUCCESS,
	STOP
};

#endif

#ifndef		ENUM_BOOLEAN
	#define		ENUM_BOOLEAN

enum		boolean {
	FALSE = 0,
	TRUE
};

#endif

#endif
