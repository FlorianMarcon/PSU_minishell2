/*
** EPITECH PROJECT, 2017
** run_left_chevron
** File description:
** run_left_chevron
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_shell.h"

int	run_left_chevron(shell_t *shell, tree_t *tree)
{
	char *file = get_name_in_tree(tree->right);
	int fd[2] = {open(file, O_RDONLY), -1};

	if (fd[0] == -1)
		return (1);
	run_cmd(shell, tree->left, NULL, fd);
	close(fd[0]);
	return (0);
}
