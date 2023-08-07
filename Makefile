# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/08/07 15:32:51 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

INCLUDES		= include

SRC_FILES		:= io/ft_putchar_fd.c \
				   io/ft_putendl_fd.c \
				   io/ft_putnbr_fd.c \
				   io/ft_putstr_fd.c \
				   mem/ft_bzero.c \
				   mem/ft_calloc.c \
				   mem/ft_memccpy.c \
				   mem/ft_memchr.c \
				   mem/ft_memcmp.c \
				   mem/ft_memcpy.c \
				   mem/ft_memmove.c \
				   mem/ft_memset.c \
				   string/ft_atoi.c \
				   string/ft_isalnum.c \
				   string/ft_isalpha.c \
				   string/ft_isascii.c \
				   string/ft_isdigit.c \
				   string/ft_isprint.c \
				   string/ft_itoa.c \
				   string/ft_split.c \
				   string/ft_strchr.c \
				   string/ft_strdup.c \
				   string/ft_striteri.c \
				   string/ft_strjoin.c \
				   string/ft_strlcat.c \
				   string/ft_strlcpy.c \
				   string/ft_strlen.c \
				   string/ft_strmapi.c \
				   string/ft_strncmp.c \
				   string/ft_strnstr.c \
				   string/ft_strrchr.c \
				   string/ft_strtrim.c \
				   string/ft_substr.c \
				   string/ft_tolower.c \
				   string/ft_toupper.c

BONUS_FILES		:=

SRC_FOLDER		= src
BONUS_FOLDER	= $(SRC_FOLDER)/bonus

SRC_FILES		:= $(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
BONUS_FILES		:= $(addprefix $(BONUS_FOLDER)/, $(BONUS_FILES))

OBJ				= $(SRC_FILES:.c=.o)
BONUS_OBJ		= $(BONUS_FILES:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
COPTS			= -fPIC -I $(INCLUDES) -g

AR				= ar rcs
RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus:			$(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

%.o:			%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean:			clean
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
