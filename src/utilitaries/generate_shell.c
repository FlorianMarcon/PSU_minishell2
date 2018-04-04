/*
** EPITECH PROJECT, 2017
** generate_shell
** File description:
** generate_shell
*/

#include <unistd.h>
#include <stdbool.h>
#include "header_shell.h"
#include "hash_map.h"
#include "environment.h"
#include "binary.h"

shell_t	*generate_shell(char **envp)
{
	shell_t *shell = malloc(sizeof(*shell));
	hm_object_t *obj;
	char *str = NULL;

	if (shell == NULL)
		return (NULL);
	shell->env = generate_hm_env(envp);
	shell->list_env = envp;
	getcwd(shell->pwd, sizeof(shell->pwd));
	shell->old_pwd = NULL;
	obj = hm_get_object(shell->env, "PATH");
	if (obj != NULL)
		str = (char *)obj->data;
	shell->binary = generate_hm_binary(str);
	shell->exit = false;
	return (shell);
}
