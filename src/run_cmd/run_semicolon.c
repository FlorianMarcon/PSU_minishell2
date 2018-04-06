/*
** EPITECH PROJECT, 2017
** run_semicolon
** File description:
** run_semicolon
*/

#include "header_shell.h"

int	run_semicolon(shell_t *shell, tree_t *tree)
{
	run_cmd(shell, tree->left, NULL, NULL);
	run_cmd(shell, tree->right, NULL, NULL);
	return (0);
}
