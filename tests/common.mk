# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    common.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:16:51 by kiroussa          #+#    #+#              #
#    Updated: 2024/06/28 18:22:01 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TEST_NAME
	$(error TEST_NAME is not set)
endif

ifndef SRC
	$(error SRC is not set)
endif

SRC_DIR = src
SRC := $(shell echo $(SRC) | tr ' ' '\n' | tac -)
SRC	:= $(addprefix $(SRC_DIR)/, $(SRC))
INCLUDE_DIR = include

CC = clang
CFLAGS = -g3 -Wno-format

LIBFT_DIR = ../..
LIBFT = $(LIBFT_DIR)/build/output/libft.a

USE_VALGRIND ?= 0
VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

all:
	@if [ ! -f $(LIBFT) ]; then \
		echo "libft is not built."; \
		exit 1; \
	fi
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I ../ $(SRC) ../test_runtime.c -DBUILD -DTEST_NAME='"$(TEST_NAME)"' -o $(TEST_NAME) $(LIBFT) -I $(LIBFT_DIR)/include
ifeq ($(USE_VALGRIND), 1)
	@$(VALGRIND) ./$(TEST_NAME)
else
	@./$(TEST_NAME)
endif
	@rm -f $(TEST_NAME)

executable:
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I ../ $(SRC) ../test_runtime.c -DBUILD -DTEST_NAME='"$(TEST_NAME)"' -o $(TEST_NAME) $(LIBFT) -I $(LIBFT_DIR)/include

print_%:
	@echo $($*)
