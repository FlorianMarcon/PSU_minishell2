/*
** EPITECH PROJECT, 2017
** get_next_instruction
** File description:
** get_next_instruction
*/

#include "tree.h"
#include "my.h"
#include "header_shell.h"

tree_t	*get_next_instruction(int fd)
{
	char *str = get_next_line(fd);
	char **tab;
	tree_t *cmd;

	if (str == NULL || (tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (NULL);
	cmd = parsing_command_line(tab);
	free(str);
//	free(tab);
	if (cmd == NULL)
		return (NULL);
	else
		return (cmd);
}
