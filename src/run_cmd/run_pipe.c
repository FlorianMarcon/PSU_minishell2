/*
** EPITECH PROJECT, 2017
** run_pipe
** File description:
** run_pipe
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_shell.h"
#include "tree.h"

int	*create_pipe(void)
{
	int *fd = malloc(sizeof(*fd) * 2);

	if (fd == NULL)
		return (NULL);
	if (pipe(fd) == -1) {
		free(fd);
		return (NULL);
	}
	return (fd);
}
int	run_pipe(shell_t *shell, tree_t *tree)
{
	int *fd = create_pipe();
	int stdin = dup(0);
	int stdout = dup(1);

	if (fd == NULL)
		return (1);
	run_cmd(shell, tree->left, fd, -1);
	run_cmd(shell, tree->right, NULL, -1);
	close(fd[0]);
	free (fd);
	dup2(stdin, 0);
	dup2(stdout, 1);
	close(stdin);
	close(stdout);
	return (0);
}
