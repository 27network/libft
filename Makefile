# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/11/17 22:24:28 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME			=	ft
LIBSTATIC		=	lib$(LIBNAME).a
LIBSHARE		= 	lib$(LIBNAME).so
NAME			= 	$(LIBSTATIC)

BUILD_FOLDER	= 	build
OUTPUT_FOLDER	= 	$(BUILD_FOLDER)/output

SRC_FILES		=  	data/list/ft_lstadd_back.c \
				   	data/list/ft_lstadd_front.c \
				   	data/list/ft_lstclear.c \
				   	data/list/ft_lstdelone.c \
				   	data/list/ft_lstiter.c \
				   	data/list/ft_lstlast.c \
				   	data/list/ft_lstmap.c \
				   	data/list/ft_lstnew.c \
					data/list/ft_lstremove.c \
					data/list/ft_lstsize.c \
				   	io/get_next_line.c \
				   	mem/ft_bzero.c \
				   	mem/ft_calloc.c \
				   	mem/ft_memchr.c \
				   	mem/ft_memcmp.c \
				   	mem/ft_memcpy.c \
				   	mem/ft_memmove.c \
				   	mem/ft_memset.c \
					print/printf/flag/pf_hash_mutator.c \
					print/printf/flag/pf_leftjustify_mutator.c \
					print/printf/flag/pf_padding_mutator.c \
					print/printf/flag/pf_precision_mutator.c \
					print/printf/str/pf_str_append.c \
					print/printf/str/pf_str_create.c \
					print/printf/str/pf_str_init.c \
					print/printf/type/pf_format_char.c \
					print/printf/type/pf_format_hex.c \
					print/printf/type/pf_format_int.c \
					print/printf/type/pf_format_lenptr.c \
					print/printf/type/pf_format_percent.c \
					print/printf/type/pf_format_pointer.c \
					print/printf/type/pf_format_strerror.c \
					print/printf/type/pf_format_string.c \
					print/printf/type/pf_format_uint.c \
					print/printf/utils/pf_append.c \
					print/printf/utils/pf_prepend_sign.c \
					print/printf/utils/pf_strnjoin.c \
					print/printf/wrapper/ft_asprintf.c \
					print/printf/wrapper/ft_dprintf.c \
					print/printf/wrapper/ft_format.c \
					print/printf/wrapper/ft_printf.c \
					print/printf/wrapper/ft_vdprintf.c \
					print/printf/wrapper/ft_vformat.c \
					print/printf/wrapper/ft_vprintf.c \
					print/printf/ft_vasprintf.c \
					print/printf/pf_format_spec.c \
					print/printf/pf_free_spec.c \
					print/printf/pf_parse_spec.c \
					print/ft_putchar.c \
					print/ft_putchar_fd.c \
				   	print/ft_putendl.c \
				   	print/ft_putendl_fd.c \
				   	print/ft_putnbr.c \
				   	print/ft_putnbr_fd.c \
				   	print/ft_putstr.c \
				   	print/ft_putstr_fd.c \
					string/atox/ft_atof.c \
					string/atox/ft_atoi.c \
					string/atox/ft_atoll.c \
					string/atox/ft_atoui.c \
					string/atox/ft_atoull.c \
					string/compare/ft_isalnum.c \
					string/compare/ft_isalpha.c \
					string/compare/ft_isascii.c \
					string/compare/ft_isdigit.c \
					string/compare/ft_islower.c \
					string/compare/ft_isprint.c \
					string/compare/ft_isspace.c \
					string/compare/ft_isupper.c \
					string/compare/ft_strcmp.c \
					string/compare/ft_strncmp.c \
					string/create/ft_ctostr.c \
					string/create/ft_split.c \
					string/create/ft_splits.c \
					string/create/ft_strbuild.c \
					string/create/ft_strdup.c \
					string/create/ft_strdup_range.c \
					string/create/ft_strjoin.c \
					string/create/ft_strmapi.c \
					string/create/ft_strndup.c \
					string/create/ft_strnew.c \
					string/create/ft_strtrim.c \
					string/create/ft_substr.c \
					string/mutate/ft_stpcpy.c \
					string/mutate/ft_strappend.c \
					string/mutate/ft_strcat.c \
					string/mutate/ft_strcpy.c \
					string/mutate/ft_strlcat.c \
					string/mutate/ft_strlcpy.c \
					string/mutate/ft_strncat.c \
					string/mutate/ft_strncpy.c \
					string/mutate/ft_strprepend.c \
					string/mutate/ft_tolower.c \
					string/mutate/ft_toupper.c \
					string/query/ft_lllen.c \
					string/query/ft_lllen_base.c \
					string/query/ft_strall.c \
					string/query/ft_strany.c \
					string/query/ft_strchr.c \
					string/query/ft_striteri.c \
					string/query/ft_strlen.c \
					string/query/ft_strnstr.c \
					string/query/ft_strrchr.c \
					string/query/ft_strstr.c \
					string/query/ft_ulllen.c \
					string/query/ft_ulllen_base.c \
					string/xtoa/ft_lltoa.c \
					string/xtoa/ft_lltoa_base.c \
					string/xtoa/ft_ulltoa.c \
					string/xtoa/ft_ulltoa_base.c \
					string/ft_strdel.c

SRC_FOLDER		= 	src
SRC_FILES		:= 	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))

OBJ_CACHE		= 	$(BUILD_FOLDER)/objects
OBJ				= 	$(SRC_FILES:.c=.o)
OBJ_CACHE_FILES	:=	$(addprefix $(OBJ_CACHE)/, $(OBJ))
OBJ_CACHE_DIRS	:=	$(sort $(patsubst %, %, $(dir $(OBJ_CACHE_FILES))))

INCLUDE_DIR		= 	include

CC				=	clang
CFLAGS			= 	-Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS		+= 	-g3
endif
COPTS			= 	-fPIC -I $(INCLUDE_DIR)

# Feature flags
ifdef FT_LOG_LEVEL
	COPTS		+= 	-DFT_LOG_LEVEL=$(FT_LOG_LEVEL)
endif

AR				= 	ar rcs
RM				= 	rm -rf

#
# Rules
#

all:			$(NAME) so | _header

_header:
	@echo libft-neo v$(shell cat version) by kiroussa

$(NAME):		$(OUTPUT_FOLDER)/$(NAME)

$(OUTPUT_FOLDER)/$(NAME):	$(OBJ_CACHE_FILES) | $(OUTPUT_FOLDER)
	$(AR) $(OUTPUT_FOLDER)/$(NAME) $(OBJ_CACHE_FILES)

so:				$(LIBSHARE)

$(LIBSHARE):	$(OUTPUT_FOLDER)/$(LIBSHARE)

$(OUTPUT_FOLDER)/$(LIBSHARE):	$(OBJ_CACHE_FILES) | $(OUTPUT_FOLDER)
	$(CC) $(CFLAGS) $(COPTS) -nostartfiles -shared -o $(OUTPUT_FOLDER)/$(LIBSHARE) $(OBJ_CACHE_FILES)

$(OBJ_CACHE)/%.o:	%.c | $(OBJ_CACHE_DIRS)
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

$(OBJ_CACHE_DIRS): | $(OBJ_CACHE)
	mkdir -p $(OBJ_CACHE_DIRS)

$(OBJ_CACHE):
	mkdir -p $(OBJ_CACHE)

$(OUTPUT_FOLDER):
	mkdir -p $(OUTPUT_FOLDER)

clean:
	$(RM) $(OBJ_CACHE)

fclean:			clean
	$(RM) $(BUILD_FOLDER)

re:				fclean all

.PHONY:			all clean fclean re so
