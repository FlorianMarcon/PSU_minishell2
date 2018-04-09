/*
** EPITECH PROJECT, 2017
** exit
** File description:
** exit
*/

#include "header_shell.h"
#include "my.h"

int	exit_program(shell_t *shell, char **cmd, int *fd, int *redi)
{
	(void)fd;
	(void)redi;
	if (len_tab(cmd) > 2)
		return (1);
	shell->exit = true;
	if (len_tab(cmd) == 2) {
		shell->value_exit = my_getnbr(cmd[1]);
	} else
		shell->value_exit = 0;
	return (0);
}
