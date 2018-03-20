/*
** EPITECH PROJECT, 2017
** environnement
** File description:
** environnement
*/

#ifndef ENV_
#define ENV_

#include "my.h"
#include "hash_map.h"

// generate_hm_env

linked_list_t	*generate_arg_var_env(char *arg);

char	*generate_name_var_env(char *str);

hash_map_t	*generate_hm_env(char **envp);

#endif
