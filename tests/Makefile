# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:44:19 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/22 06:15:48 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS = $(wildcard */Makefile)
TESTS := $(foreach dir,$(TESTS),$(shell dirname $(dir)))

MAKE = make -i --no-print-directory

LIBFT_DIR = ..
LIBFT = $(LIBFT_DIR)/build/output/libft.so
USE_VALGRIND = 0

all:  $(TESTS)

$(TESTS): $(LIBFT)
	@printf "> \033[1;34m%s\033[m\n" $@
	@$(MAKE) -C $@ USE_VALGRIND=$(USE_VALGRIND)

valgrind:
	@$(MAKE) USE_VALGRIND=1 all

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -j
	@printf "\33[2K\r"

.PHONY: all $(TESTS)
