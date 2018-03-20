/*
** EPITECH PROJECT, 2017
** generate_hm_env
** File description:
** generate_hm_env
*/

#include "environment.h"
#include "hash_map.h"
#include "my_printf.h"
#include "my.h"

hash_map_t	*generate_hm_env(char **envp)
{
	char *name = NULL;
	linked_list_t *list = NULL;
	hash_map_t *hm = generate_hash_map(SIZE_HM);

	if (hm == NULL)
		return (NULL);
	for (unsigned int i = 0; envp[i] != NULL; i++) {
		if ((name = generate_name_var_env(envp[i])) == NULL) {

		} else if ((list = generate_arg_var_env(&envp[i][my_strlen(name) + 1])) == NULL)
			free(name);
		else {
			hm_add_object(hm, name, list);
			free(name);
		}
	}
	return (hm);
}
