##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

LIB	=	lib/transform_character.c	\
		lib/tools_function.c	\
		lib/get_next_line.c	\
		lib/str_to_array.c	\
		lib/my_putarray.c	\
		lib/my_strcpy.c		\
		lib/my_strdup.c

SRC	=	solver/src/help_page.c		\
		solver/src/dante.c			\
		solver/src/read_file.c		\
		solver/src/initialise.c		\
		solver/src/map.c			\
		solver/src/tools_function.c	\
		solver/src/closed_open.c	\
		solver/src/pos.c

OBJ	=	$(SRC:.c=.o)

LIB_OBJ	=	$(LIB:.c=.o)

COVERAGE	=	$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\
				$(TEST_SRC:.c=.gcno)	\
				$(LIB:.c=.gcda)	\
				$(LIB:.c=.gcno)	\
				$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)

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

%.o:	%.c
	@$(CC) $(LFLAGS) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34m-Compiled-\e[0m] % 41s\n" $@ | tr ' ' '.'

clean: ## Clean the useless file
	@rm -f $(OBJ) $(MAIN_OBJ) $(LIB_OBJ) $(TEST_OBJ) $(COVERAGE)

fclean:	clean ## Clean the project
	@rm -f $(TARGET) $(TEST_TARGET)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TEST_TARGET) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"

re:	fclean all ## Clean then compile

tests_run: CFLAGS += --coverage ## Launch tests
tests_run:	$(OBJ)	$(TEST_OBJ)	$(LIB_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) $(LIB_OBJ) -o $(TEST_TARGET) $(TEST_LFLAGS)
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Tests the code ▄▀▄▀▄▀\e[0m\n"
	@./$(TEST_TARGET)
	@gcovr --exclude tests/

re_tests: fclean tests_run ## Clean then tests

valgrind:	CFLAGS += -g3
valgrind:	fclean	all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) maps/map1

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help