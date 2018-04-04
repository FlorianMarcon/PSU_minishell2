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

	char **ptr_env;
//	tree_t *cmd;
}shell_t;

int	minishell(shell_t *shell);

// utilitaries

int	is_executable(char *path);

int	search_index_operator(char **cmd);

int	is_operator(char *str);

tree_t	*parsing_command_line(char **cmd);

char	**create_tab_op_for_command_line(char *str);

tree_t	*get_next_instruction(int fd);

shell_t	*generate_shell(char **envp);

char	*get_path(hash_map_t *map_binary, char *cmd);

int	is_operator(char *str);

// builtin

void	print_env_variable(hm_object_t *obj);

void	env(hash_map_t *env);

// run cmd

void	run_cmd(shell_t *shell, tree_t *tree);

// execution

int	basic_exec(shell_t *shell, char **cmd);

#endif
