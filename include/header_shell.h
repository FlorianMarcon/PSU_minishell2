/*
** EPITECH PROJECT, 2017
** header_shell
** File description:
** header_shell
*/

#ifndef SHELL_
#define SHELL_

#include <stdbool.h>
#include "hash_map.h"
#include "tree.h"

typedef struct shell_s {
	// var env
	hash_map_t *env;
	char **list_env;
	char pwd[100];
	char *old_pwd;

	//binary
	hash_map_t *binary;

	//
	bool exit;
	int value_exit;

}shell_t;

int	minishell(shell_t *shell);

// utilitaries

int	is_executable(char *path);

int	search_index_operator(char **cmd);

int	is_operator(char *str);

tree_t	*parsing_command_line(char **cmd);

char	**create_tab_op_for_command_line(char *str);

tree_t	*get_next_instruction(shell_t *shell, int fd);

shell_t	*generate_shell(char **envp);

char	*get_path(hash_map_t *map_binary, char *cmd);

int	is_operator(char *str);

char	**my_addtab(char **tab, char *str);

// builtin

typedef struct built_s {
	char *label;
	int (*ptr)(shell_t *, char **);
}built_t;

int	env(shell_t *shell, char **cmd);

int	exit_program(shell_t *shell, char **cmd);

int	current_directory(shell_t *shell, char **cmd);

// run cmd

typedef struct optab_s {
	char *label;
	int (*ptr)(shell_t *shell, tree_t *tree);
}optab_t;

int	run_pipe(shell_t *shell, tree_t *tree);

static const optab_t run_op[8] = {
	{";", NULL},
	{"|", run_pipe},
	{"&", NULL},
	{"<", NULL},
	{"<<", NULL},
	{">", NULL},
	{">", NULL},
	{NULL, NULL}
};

void	run_cmd(shell_t *shell, tree_t *tree, int *fd, int redi);

// execution

int	basic_exec(shell_t *shell, char **cmd, int *fd, int redi);

#endif
