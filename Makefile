# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/08/08 21:02:21 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRC_FILES		:= ft_putchar_fd.c \
				   ft_putendl_fd.c \
				   ft_putnbr_fd.c \
				   ft_putstr_fd.c \
				   ft_bzero.c \
				   ft_calloc.c \
				   ft_memchr.c \
				   ft_memcmp.c \
				   ft_memcpy.c \
				   ft_memmove.c \
				   ft_memset.c \
				   ft_atoi.c \
				   ft_isalnum.c \
				   ft_isalpha.c \
				   ft_isascii.c \
				   ft_isdigit.c \
				   ft_isprint.c \
				   ft_itoa.c \
				   ft_split.c \
				   ft_strchr.c \
				   ft_strdup.c \
				   ft_striteri.c \
				   ft_strjoin.c \
				   ft_strlcat.c \
				   ft_strlcpy.c \
				   ft_strlen.c \
				   ft_strmapi.c \
				   ft_strncmp.c \
				   ft_strnstr.c \
				   ft_strrchr.c \
				   ft_strtrim.c \
				   ft_substr.c \
				   ft_tolower.c \
				   ft_toupper.c

BONUS_FILES		:= ft_lstadd_back.c \
				   ft_lstadd_front.c \
				   ft_lstclear.c \
				   ft_lstdelone.c \
				   ft_lstiter.c \
				   ft_lstlast.c \
				   ft_lstmap.c \
				   ft_lstnew.c \
				   ft_lstsize.c

SRC_FOLDER		= .

SRC_FILES		:= $(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
BONUS_FILES		:= $(addprefix $(SRC_FOLDER)/, $(BONUS_FILES))

OBJ				= $(SRC_FILES:.c=.o)
BONUS_OBJ		= $(BONUS_FILES:.c=.o)

INCLUDES		= .

CC				= clang
CFLAGS			= -Wall -Wextra -Werror
COPTS			= -fPIC -I $(INCLUDES)

AR				= ar rcs
RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus:			$(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

%.o:			%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean:			clean
	$(RM) $(NAME) $(LIBSHARE)

re:				fclean all

.PHONY:			all clean fclean re bonus
