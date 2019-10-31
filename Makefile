# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarx <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 17:45:06 by tmarx             #+#    #+#              #
#    Updated: 2019/10/29 11:28:16 by tmarx            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_SRC=./test/main.c
TEST_BIN=./bin/test
TEST_FLAGS=-g3 -fsanitize=address

LIB=libftprintf.a
SRC=./src/printf.c\
	./src/str_utils.c\
	./src/utils.c\
	./src/print_types.c
OBJ=./obj/printf.o\
	./obj/str_utils.o\
	./obj/utils.o\
	./obj/print_types.o

FLAGS=-Werror -Wextra -Werror -I./includes/

all: ${LIB}

test: ${LIB} ${TEST_BIN}
	@echo "\033[0;32m=== Executing test binary... ===\033[0m"
	@${TEST_BIN}

norme:
	@echo "\033[0;32m=== Checking the norme... ===\033[0m"
	@norminette ./src/*.c
	@norminette ./includes/*.h

${TEST_BIN}: ${TEST_SRC} ${SRC}
	@echo "\033[0;32m=== Making the test binary... ===\033[0m"
	mkdir -p ./bin/
	gcc ${TEST_SRC} ${FLAGS} ${TEST_FLAGS} -L. -lftprintf -I./includes/ -o ${TEST_BIN} -L./includes/ -lft

${LIB}: ${OBJ}
	@echo "\033[0;32m=== Making the lib... ===\033[0m"
	ar rcs ${LIB} ${OBJ}

./obj/%.o: ./src/%.c
	mkdir -p ./obj/
	gcc ${FLAGS} -c $< -o $@

re: fclean all

clean:
	@echo "\033[0;32m=== Cleaning object files... ===\033[0m"
	rm -f ./obj/*

fclean: clean
	@echo "\033[0;32m=== Cleanup... ===\033[0m"
	rm -rf ./bin/*
	rm -rf ${LIB}

.PHONY: test re
