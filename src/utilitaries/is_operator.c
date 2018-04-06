/*
** EPITECH PROJECT, 2017
** is_operator
** File description:
** is_operator
*/

#include "my.h"

int	is_operator(char *str, int n)
{
	int a = 0;
	const char *operator[8]  = {
		";",
		"|",
		"&",
		">",
		">>",
		"<<",
		"<",
		NULL
	};

	if (str == NULL)
		return (0);
	while (operator[a] != NULL)
		if (my_strncmp(operator[a++], str, n) == 0)
			return (1);
	return (0);
}
