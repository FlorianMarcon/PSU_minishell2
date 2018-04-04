/*
** EPITECH PROJECT, 2017
** shell
** File description:
** shell
*/

#include "header_shell.h"
#include "tree.h"

int	minishell(shell_t *shell)
{
	(void)shell;
	tree_t *cmd;

	while (1) {
		cmd = get_next_instruction(0);
		if (cmd == NULL)
			my_printf("Bad instructions\n");
		else {
			run_cmd(shell, cmd);
			free(cmd);
		}
	}
}
