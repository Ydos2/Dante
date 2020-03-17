##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	create_empty_maze.c	\
		create_wandering_path.c		\
		perfect/add_perfect_path.c \
		perfect/generate_perfect_maze.c \
		imperfect/generate_imperfect_maze.c

OBJ	=	$(SRC:.c=.o)

COVERAGE	=	$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\
				$(TEST_SRC:.c=.gcno)	\
				$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)

MAIN_SRC	=	main.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I../include -Wextra -W -Wall -pedantic

TARGET	=	generator

TEST_SRC	=	tests/initisation.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

TEST_TARGET	=	unit_tests

TEST_LFLAGS	=	-lcriterion

all:	$(TARGET) ## Build the project

$(TARGET):	build

build:	$(OBJ)	$(MAIN_OBJ) ## Compile the project
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET)
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Link all object ▄▀▄▀▄▀\e[0m\n"

%.o:	%.c
	@$(CC) $(LFLAGS) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34m-Compiled-\e[0m] % 41s\n" $@ | tr ' ' '.'

clean: ## Clean the useless file
	@rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(COVERAGE)

fclean:	clean ## Clean the project
	@rm -f $(TARGET) $(TEST_TARGET)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TEST_TARGET) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"

re:	fclean all ## Clean then compile

tests_run: CFLAGS += --coverage ## Launch tests
tests_run:	$(OBJ)	$(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_TARGET) $(TEST_LFLAGS)
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Tests the code ▄▀▄▀▄▀\e[0m\n"
	@./$(TEST_TARGET)
	@gcovr --exclude tests/

re_tests: fclean tests_run ## Clean then tests

valgrind:	CFLAGS += -g3
valgrind:	fclean	all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help