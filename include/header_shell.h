/*
** EPITECH PROJECT, 2017
** header_shell
** File description:
** header_shell
*/

#ifndef SHELL_
#define SHELL_

#include "hash_map.h"
#include "tree.h"

typedef struct shell_s {
	hash_map_t *env;
	hash_map_t *binary;
//	tree_t *cmd;
}shell_t;

// utilitaries

int	is_executable(char *path);

int	search_index_operator(char **cmd);

int	is_operator(char *str);

tree_t	*parsing_command_line(char **cmd);

char	**create_tab_op_for_command_line(char *str);

tree_t	*get_next_instruction(int fd);

shell_t	*generate_shell(char **envp);

// builtin

void	print_env_variable(hm_object_t *obj);

void	env(hash_map_t *env);

#endif
