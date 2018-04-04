/*
** EPITECH PROJECT, 2017
** shell
** File description:
** shell
*/

#include <stdbool.h>
#include "header_shell.h"
#include "tree.h"

int	minishell(shell_t *shell)
{
	(void)shell;
	tree_t *cmd;

	while (shell->exit == false) {
		cmd = get_next_instruction(0);
		if (cmd == NULL)
			my_printf("Bad instructions\n");
		else {
			run_cmd(shell, cmd);
			free(cmd);
		}
	}
	return (shell->value_exit);
}
