/*
** EPITECH PROJECT, 2017
** env
** File description:
** env
*/

#include "hash_map.h"
#include "header_shell.h"

int	env(shell_t *shell, char **cmd)
{
	char **env = shell->list_env;

	if (env == NULL)
		return (1);
	if (cmd[1] != NULL) {
		my_printf("env: «%s»: Aucun fichier ou dossier de ce type",
									cmd[1]);
		return (1);
	}
	for (unsigned int i = 0; env[i] != NULL; i++)
		my_printf("%s\n", env[i]);
	return (0);
}
