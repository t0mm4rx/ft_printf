# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarx <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 17:45:06 by tmarx             #+#    #+#              #
#    Updated: 2019/11/05 11:59:01 by tmarx            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_SRC=./test/main.c
TEST_BIN=./bin/test
TEST_FLAGS=-g3 -fsanitize=address

LIBFT=libft.a
LIBFT_SRC=${wildcard libft/*}
LIBFT_OBJ=${LIBFT_SRC:%.c=%.o}

LIB=libftprintf.a
SRC=./src/printf.c\
	./src/str_utils.c\
	./src/utils.c\
	./src/print_types.c\
	./src/hex.c\
	./src/print_types2.c\
	./src/parsing.c
OBJ=./obj/printf.o\
	./obj/str_utils.o\
	./obj/utils.o\
	./obj/print_types.o\
	./obj/hex.o\
	./obj/print_types2.o\
	./obj/parsing.o

FLAGS=-Wall -Wextra -Werror -I./includes/

all: ${LIB}

test: ${LIB} ${TEST_BIN}
	@echo "\033[0;32m=== Executing test binary... ===\033[0m"
	@${TEST_BIN}

norme:
	@echo "\033[0;32m=== Checking the norme... ===\033[0m"
	@norminette ./src/*.c
	@norminette ./includes/*.h
	@cat ./src/* | grep stdio.h
	@cat ./src/* | grep printf
	@cat ./src/* | grep puts

${TEST_BIN}: ${TEST_SRC} ${SRC}
	@echo "\033[0;32m=== Making the test binary... ===\033[0m"
	mkdir -p ./bin/
	gcc ${TEST_SRC} ${FLAGS} ${TEST_FLAGS} -L. -lft -L. -lftprintf -o ${TEST_BIN}

${LIB}: ${LIBFT} ${OBJ}
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
	rm -rf ./libft/*.o
	rm -rf ${LIB}
	rm -rf ${LIBFT}

./libft/%.o: ./libft/%.c
	gcc ${FLAGS} -c $< -o $@

${LIBFT}: ${LIBFT_OBJ}
	@echo "\033[0;32m=== Making libft... ===\033[0m"
	ar rcs ${LIBFT} ${LIBFT_OBJ}

.PHONY: test re
