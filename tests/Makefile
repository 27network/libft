# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 23:58:42 by kiroussa          #+#    #+#              #
#    Updated: 2023/10/26 04:02:14 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tests
CC = clang
CFLAGS = -Wall -Wextra -Werror -I./ -I../include -DFT_LOG_LEVEL=TRACE

SRC = $(shell find . -type f -name "*.c")
OBJ = $(SRC:.c=.o)

all: libft run

#TODO: add per-file compilation/run

run: 
	@echo Running all tests

libft:
	make -C ../ FT_LOG_LEVEL=TRACE 

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re run
