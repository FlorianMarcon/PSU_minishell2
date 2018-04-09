/*
** EPITECH PROJECT, 2017
** run_cmd
** File description:
** run_cmd
*/

#include <unistd.h>
#include "tree.h"
#include "header_shell.h"
#include "my.h"

void	alpha(int *fd, int *redi);

int	search_and_run_builtin(shell_t *shell, char **cmd, int *fd, int *redi)
{
	if (cmd[0] == NULL)
		return (1);
	for (unsigned int i = 0; builtin[i].label != NULL; i++) {
		if (my_strcmp(cmd[0], builtin[i].label) == 0) {
			builtin[i].ptr(shell, cmd, fd, redi);
			if (fd != NULL) {
				dup2(fd[0], 0);
				close(fd[1]);
			}
			return (0);
		}
	}
	return (1);
}

int	run_operator(shell_t *shell, tree_t *tree, char **cmd)
{
	for (unsigned int i = 0; run_op[i].label != NULL; i++) {
		if (my_strcmp(run_op[i].label, cmd[0]) == 0 &&
						run_op[i].ptr != NULL) {
			run_op[i].ptr(shell, tree);
			return (0);
		}
	}
	return (0);
}

void	run_cmd(shell_t *shell, tree_t *tree, int *fd, int *redi)
{
	char **tab;

	if (tree == NULL || (tab = (char **)(tree->data)) == NULL)
		return;
	if (is_operator(tab[0])) {
		run_operator(shell, tree, tab);
	} else {
		if (search_and_run_builtin(shell, tab, fd, redi))
			basic_exec(shell, tab, fd, redi);
	}
}
