# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarx <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 17:45:06 by tmarx             #+#    #+#              #
#    Updated: 2019/10/28 14:36:26 by tmarx            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_SRC=./test/main.c
TEST_BIN=./bin/test
TEST_FLAG=-g3 -fsanitize=address

LIB=libftprintf.a
SRC=./src/printf.c\
	./src/str_utils.c\
	./src/utils.c\
	./src/print_types.c
OBJ=./obj/printf.o\
	./obj/str_utils.o\
	./obj/utils.o\
	./obj/print_types.o

FLAGS=-Werror -Wextra -Werror

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
	gcc ${TEST_SRC} ${TEST_FLAG} -L. -lftprintf -I./includes/ -o ${TEST_BIN}

${LIB}: ${OBJ}
	@echo "\033[0;32m=== Making the lib... ===\033[0m"
	ar rcs ${LIB} ${OBJ}

./obj/%.o: ./src/%.c
	mkdir -p ./obj/
	gcc ${FLAGS} -I./includes/ -c $< -o $@

re: fclean all

clean:
	@echo "\033[0;32m=== Cleaning object files... ===\033[0m"
	rm -f ./obj/*

fclean: clean
	@echo "\033[0;32m=== Cleanup... ===\033[0m"
	rm -rf ./bin/*
	rm -rf ${LIB}

.PHONY: test re
