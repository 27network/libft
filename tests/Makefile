# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 23:58:42 by kiroussa          #+#    #+#              #
#    Updated: 2023/10/27 02:13:29 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tests
CC = clang
CFLAGS = -Wall -Wextra -g -I./ -I../include -DFT_LOG_LEVEL=TRACE

SRC = $(shell find . -type f -name "*.c")
TESTS = $(basename $(notdir $(SRC)))
OBJ = $(SRC:.c=.o)

all: libft run

#TODO: add per-file compilation/run

tests: $(OBJ)

run: tests
	@echo Running all tests
	$(foreach test, $(OBJ), ./$(test);)

%.o: %.c
	$(CC) $(CFLAGS) $< ../libft.a -o $@

libft:
	make -C ../ FT_LOG_LEVEL=TRACE 

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re run tests
