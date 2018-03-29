/*
** EPITECH PROJECT, 2017
** exec
** File description:
** exec
*/

#include "my.h"

int	basic_exec(char **cmd, char **env)
{
	int lock;
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(cmd[0], cm, env);
	else {
		waitpid(pid, &lock, 0);
	}
}
