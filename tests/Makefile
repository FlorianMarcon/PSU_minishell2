##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/hash_map/hash_get_key.c		\
		$(WAY)/hash_map/generate_hash_map.c	\
		$(WAY)/hash_map/hm_generate_object.c	\
		$(WAY)/hash_map/hm_get_last_object.c	\
		$(WAY)/hash_map/hm_add_object.c		\
		$(WAY)/utilitaries/is_executable.c	\
		$(WAY)/hm_binary/put_binary_in_hm.c	\
		$(WAY)/hm_binary/analyse_file.c		\
		$(WAY)/hm_binary/hm_binary_list_all_file.c	\


SRC_UT	=	hash_map/tests_utils.c			\
		utilitaries/is_executable/tests_utils.c	\
		hm_binary/tests_utils.c			\

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
