/*
** EPITECH PROJECT, 2017
** run_right_chevron
** File description:
** run_right_chevron
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header_shell.h"

int	run_right_chevron(shell_t *shell, tree_t *tree)
{
	char *file = get_name_in_tree(tree->right);
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
	int fd[2] = {-1, open(file, O_CREAT | O_RDWR | O_TRUNC, mode)};

	run_cmd(shell, tree->left, NULL, fd);
	if (fd[1] == -1)
		return (1);
	close(fd[1]);
	return (0);
}

int	run_double_right_chevron(shell_t *shell, tree_t *tree)
{
	char *file = get_name_in_tree(tree->right);
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
	int fd[2] = {-1, open(file, O_CREAT | O_RDWR | O_APPEND, mode)};

	run_cmd(shell, tree->left, NULL, fd);
	if (fd[1] == -1)
		return (1);
	close(fd[1]);
	return (0);
}
