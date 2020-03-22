##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

MAIN_SRC	=	solver/src/main.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -Wextra -W -Wall -pedantic

TEST_SRC	=	tests/initialisation.c	\
				tests/tests_lib.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

TEST_TARGET	=	unit_tests

TEST_LFLAGS	=	-lcriterion

all:	build ## Build the project

build:
	make -C generator
	make -C solver

clean: ## Clean the useless file
	make -C generator clean
	make -C solver clean

fclean:	clean ## Clean the project
	make -C generator fclean
	make -C solver fclean

re:	fclean all ## Clean then compile

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re help