##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c	\
		$(WAY)/hm_binary/hm_binary_list_all_file.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I./include

LDFLAGS	=

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	mysh

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

clean:
	make clean -C./$(WAY_TST)
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_TST)
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
