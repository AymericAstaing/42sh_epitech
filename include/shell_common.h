/*
** EPITECH PROJECT, 2018
** Shell
** File description:
** Common header
*/

#ifndef SHELL_COMMON_H_
	#define SHELL_COMMON_H_

#define		C_EXIT_SUCCESS		0
#define		C_EXIT_ERROR		84

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

#endif /* !SHELL_COMMON_H_ */
