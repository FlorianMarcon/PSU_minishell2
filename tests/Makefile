##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/shell.c	\
		$(WAY)/hash_map/hash_get_key.c		\
		$(WAY)/hash_map/generate_hash_map.c	\
		$(WAY)/hash_map/hm_generate_object.c	\
		$(WAY)/hash_map/hm_get_last_object.c	\
		$(WAY)/hash_map/hm_add_object.c		\
		$(WAY)/hash_map/hm_get_object.c		\
		$(WAY)/hash_map/hm_destroy.c		\
		$(WAY)/hm_binary/put_binary_in_hm.c	\
		$(WAY)/hm_binary/analyse_file.c		\
		$(WAY)/hm_binary/hm_binary_list_all_file.c	\
		$(WAY)/hm_binary/generate_hm_binary.c	\
		$(WAY)/hm_env/generate_name_and_arg_var_env.c	\
		$(WAY)/hm_env/generate_list_env.c	\
		$(WAY)/tree/tree_create_node.c		\
		$(WAY)/tree/tree_link_node.c		\
		$(WAY)/tree/destroy_tree.c		\
		$(WAY)/utilitaries/is_executable.c	\
		$(WAY)/utilitaries/search_index_operator.c	\
		$(WAY)/utilitaries/parsing_command_line.c	\
		$(WAY)/utilitaries/get_next_instruction.c	\
		$(WAY)/utilitaries/generate_shell.c	\
		$(WAY)/utilitaries/get_path.c		\
		$(WAY)/utilitaries/is_operator.c	\
		$(WAY)/utilitaries/my_addtab.c		\
		$(WAY)/utilitaries/display_prompt.c	\
		$(WAY)/utilitaries/separation_between_instruction_operator.c\
		$(WAY)/builtin/env.c			\
		$(WAY)/builtin/current_directory.c	\
		$(WAY)/builtin/exit_program.c		\
		$(WAY)/builtin/set_env.c		\
		$(WAY)/run_cmd/run_cmd.c		\
		$(WAY)/run_cmd/run_pipe.c		\
		$(WAY)/run_cmd/run_right_chevron.c	\
		$(WAY)/run_cmd/run_left_chevron.c	\
		$(WAY)/run_cmd/run_semicolon.c		\
		$(WAY)/run_cmd/get_name_in_tree.c	\
		$(WAY)/execution/basic_exec.c		\
		$(WAY)/verification_cmd/verification_cmd.c	\
		$(WAY)/hm_env/generate_hm_env.c		\

SRC_UT	=	hash_map/tests_utils.c			\
		hash_map/tests_utils_second.c			\
		utilitaries/is_executable/tests_utils.c	\
		utilitaries/get_path/tests_utils.c	\
		utilitaries/search_index_operator/tests_utils.c	\
		utilitaries/my_tabdup/tests_utils.c	\
		utilitaries/my_addtab/tests_utils.c	\
		utilitaries/parsing_command_line/tests_utils.c	\
		utilitaries/parsing_command_line/tests_utils_second.c	\
		utilitaries/get_next_instruction/tests_utils.c	\
		utilitaries/separation_between_instruction_operator/tests_utils.c\
		hm_binary/tests_utils.c			\
		hm_binary/tests_utils_second.c		\
		tree/tree_create_node/tests_utils.c	\
		tree/tree_link_node/tests_utils.c	\
		verification_cmd/tests_utils.c		\
#		builtin/env/tests_utils.c		\
#		hm_env/tests_utils.c			\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage -I../include

LDFLAGS	=	-lcriterion -lgcov

WAY_LIB	=	../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

all:	$(OBJ) $(OBJ_UT)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	$(RM) $(NAME)

re:	clean all
