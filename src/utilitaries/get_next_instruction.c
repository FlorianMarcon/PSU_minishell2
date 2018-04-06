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

	(void)shell;

	if (str == NULL)
		return (NULL);
	str = separation_between_instruction_operator(str);
	if ((tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (NULL);
	cmd = parsing_command_line(tab);
	free(str);
	free(tab);
	if (cmd == NULL) {
		tab = create_tab_op_for_command_line(my_strdup(""));
		cmd = tree_create_node(tab, NULL, NULL);
	}
	return (cmd);
}
