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
	tree_t *cmd;

	while (shell->exit == false) {
		cmd = get_next_instruction(shell, 0);
		if (cmd != NULL) {
			run_cmd(shell, cmd);
			free(cmd);
		}
	}
	return (shell->value_exit);
}
