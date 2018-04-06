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
		display_prompt(shell);
		cmd = get_next_instruction(shell, 0);
		if (cmd == NULL) {
			shell->exit = true;
		} else {
			if (verification_cmd(cmd) == 0)
				run_cmd(shell, cmd, NULL, NULL);
			free(cmd);
		}
	}
	return (shell->value_exit);
}
