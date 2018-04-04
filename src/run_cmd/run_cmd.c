/*
** EPITECH PROJECT, 2017
** run_cmd
** File description:
** run_cmd
*/

#include "tree.h"
#include "header_shell.h"
#include "my.h"

void	run_cmd(shell_t *shell, tree_t *tree)
{
	char **tab;

	if (tree == NULL || (tab = (char **)(tree->data)) == NULL)
		return;
	if (is_operator(tab[0])) {
		run_cmd(shell, tree->right);
		run_cmd(shell, tree->left);
	} else {
		basic_exec(shell, tab);
	}
}
