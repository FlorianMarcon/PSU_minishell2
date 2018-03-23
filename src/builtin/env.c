/*
** EPITECH PROJECT, 2017
** env
** File description:
** env
*/

#include "hash_map.h"

void	print_env_variable(hm_object_t *obj)
{
	char *arg;

	while (obj != NULL) {
		my_printf("%s=\0", obj->key);
		arg = (char *)obj->data;
		if (arg != NULL)
			my_printf("%s\0", arg);
		my_printf("\n");
		obj = obj->next;
	}
}

void	env(hash_map_t *env)
{
	int i = 0;
	hm_object_t *obj;

	while (i != env->size) {
		if ((obj = env->hash_map[i]) != NULL) {
			print_env_variable(obj);
		}
		i++;
	}
}
