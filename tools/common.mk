# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    common.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 19:10:44 by kiroussa          #+#    #+#              #
#    Updated: 2024/05/28 14:41:37 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(SRC),)
$(error SRC is not set)
endif

NAME	= $(notdir $(CURDIR))
CC		?= clang
CFLAGS	?= -Wall -Wextra -Werror
LDFLAGS	?=
OBJ		= $(SRC:.c=.o)

all: $(NAME)

gitignore:
	@printf "/$(NAME)\n*.o" > .gitignore

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
