/*
** EPITECH PROJECT, 2017
** get_next_instruction
** File description:
** get_next_instruction
*/

#include "tree.h"
#include "my.h"
#include "header_shell.h"

tree_t	*get_next_instruction(shell_t *shell, int fd)
{
	char *str = get_next_line(fd);
	char **tab;
	tree_t *cmd;

	if (str == NULL) {
		shell->exit = true;
		shell->value_exit = 0;
	}
	str = separation_between_instruction_operator(str);
	if ((tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (NULL);
	cmd = parsing_command_line(tab);
	free(str);
	if (cmd == NULL)
		return (NULL);
	else
		return (cmd);
}
