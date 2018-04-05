/*
** EPITECH PROJECT, 2017
** run_cmd
** File description:
** run_cmd
*/

#include "tree.h"
#include "header_shell.h"
#include "my.h"

int	run_builtin(shell_t *shell, char **cmd)
{
	if (cmd[0] == NULL)
		return (1);
	if (my_strcmp(cmd[0], "exit") == 0) {
		exit_program(shell, cmd);
		return (0);
	} else if (my_strcmp(cmd[0], "env") == 0) {
		env(shell, cmd);
		return (0);
	}  else if (my_strcmp(cmd[0], "cd") == 0) {
		current_directory(shell, cmd);
		return (0);
	} else {
		return (1);
	}
}

void	run_cmd(shell_t *shell, tree_t *tree)
{
	char **tab;

	if (tree == NULL || (tab = (char **)(tree->data)) == NULL)
		return;
	if (is_operator(tab[0])) {
		run_cmd(shell, tree->right);
		run_cmd(shell, tree->left);
	} else {
		if (run_builtin(shell, tab))
			basic_exec(shell, tab);
	}
}
