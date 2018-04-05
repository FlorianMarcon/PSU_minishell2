/*
** EPITECH PROJECT, 2017
** exec
** File description:
** exec
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "header_shell.h"
#include "binary.h"
#include "hash_map.h"

int	basic_exec(shell_t *shell, char **cmd, int *fd, int redi)
{
	int lock;
	pid_t pid;
	char *path = get_path(shell->binary, cmd[0]);

	if (path == NULL)
		return (1);
	pid = fork();
	if (pid == 0) {
		if (fd != NULL)
			dup2(fd[1], 1);
		if (fd == NULL && redi != -1)
			dup2(redi, 1);
		execve(path, cmd, shell->list_env);
	} else {
		waitpid(pid, &lock, 0);
		if (fd != NULL) {
			dup2(fd[0], 0);
			close(fd[1]);
		}
	}
	return (0);
}
