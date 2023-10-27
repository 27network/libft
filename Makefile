# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/10/26 15:41:26 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXTRA			= 	0

LIBNAME			=	ft
LIBSTATIC		=	lib$(LIBNAME).a
LIBSHARE		= 	lib$(LIBNAME).so
NAME			= 	$(LIBSTATIC)

SRC_FILES		=	io/ft_putchar.c \
					io/ft_putchar_fd.c \
				   	io/ft_putendl.c \
				   	io/ft_putendl_fd.c \
				   	io/ft_putnbr.c \
				   	io/ft_putnbr_fd.c \
				   	io/ft_putstr.c \
				   	io/ft_putstr_fd.c \
					list/ft_lstadd_back.c \
				   	list/ft_lstadd_front.c \
				   	list/ft_lstclear.c \
				   	list/ft_lstdelone.c \
				   	list/ft_lstiter.c \
				   	list/ft_lstlast.c \
				   	list/ft_lstmap.c \
				   	list/ft_lstnew.c \
				   	list/ft_lstsize.c \
				   	log/ft_log.c \
					log/ft_log_fd.c \
					log/ft_loglevel_name.c \
				   	mem/ft_bzero.c \
				   	mem/ft_calloc.c \
				   	mem/ft_memchr.c \
				   	mem/ft_memcmp.c \
				   	mem/ft_memcpy.c \
				   	mem/ft_memmove.c \
				   	mem/ft_memset.c \
				   	string/atox/ft_atof.c \
					string/atox/ft_atoi.c \
					string/atox/ft_atoll.c \
					string/atox/ft_atoui.c \
					string/atox/ft_atoull.c \
					string/xtoa/ft_itoa_base.c \
					string/xtoa/ft_itoa.c \
				   	string/ft_isalnum.c \
				   	string/ft_isalpha.c \
				   	string/ft_isascii.c \
				   	string/ft_isdigit.c \
				   	string/ft_isprint.c \
					string/ft_isspace.c \
					string/ft_nblen.c \
				   	string/ft_split.c \
					string/ft_strall.c \
					string/ft_strany.c \
				   	string/ft_strchr.c \
					string/ft_strcmp.c \
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
					string/ft_strstr.c \
				   	string/ft_strtrim.c \
				   	string/ft_substr.c \
				   	string/ft_tolower.c \
				   	string/ft_toupper.c

	
SRC_FOLDER		= 	src
SRC_FILES		:= 	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
OBJ				= 	$(SRC_FILES:.c=.o)

INCLUDE_DIR		= 	include

CC				=	clang
CFLAGS			= 	-Wall -Wextra -Werror
COPTS			= 	-fPIC -I $(INCLUDE_DIR)

# Feature flags
ifdef FT_LOG_LEVEL
	COPTS		+= 	-DFT_LOG_LEVEL=$(FT_LOG_LEVEL)
endif

AR				= 	ar rcs
RM				= 	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
	$(AR) $(NAME) $(OBJ)

so:				$(LIBSHARE)

$(LIBSHARE):	$(OBJ)
	$(CC) $(CFLAGS) $(COPTS) -nostartfiles -shared -o $(LIBSHARE) $(OBJ)

%.o:			%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:			clean
	$(RM) $(NAME) $(LIBSHARE)

re:				fclean all

.PHONY:			all clean fclean re so
