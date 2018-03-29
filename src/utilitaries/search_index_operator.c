/*
** EPITECH PROJECT, 2017
** search_operator
** File description:
** search_operator
*/

#include "my.h"
#include "binary.h"

int	is_operator(char *str)
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

	while (operator[a] != NULL)
		if (my_strcmp(operator[a++], str) == 0)
			return (1);
	return (0);
}
int	search_index_operator(char **cmd)
{
	int i = 0;

	if (cmd == NULL)
		return (-1);
	while (cmd[i] != NULL) {
		if (my_strcmp(cmd[i++], ";") == 0)
			return (--i);
	}
	i = 0;
	while (cmd[i] != NULL) {
		if (my_strcmp(cmd[i++], "|") == 0)
			return (--i);
	}
	i = 0;
	while (cmd[i] != NULL) {
		if (is_operator(cmd[i++]))
			return (--i);
	}
	return (-1);
}
