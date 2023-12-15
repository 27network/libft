# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/12/15 19:08:10 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME			=	ft
LIBSTATIC		=	lib$(LIBNAME).a
LIBSHARE		= 	lib$(LIBNAME).so
NAME			= 	$(LIBSTATIC)

BUILD_FOLDER	= 	build
OUTPUT_FOLDER	= 	$(BUILD_FOLDER)/output

SRC_FILES		=  	data/list/ft_lst_add.c \
				   	data/list/ft_lst_insert.c \
				   	data/list/ft_lst_free.c \
					data/list/ft_lst_get.c \
				   	data/list/ft_lst_delete.c \
				   	data/list/ft_lst_foreach.c \
				   	data/list/ft_lst_last.c \
				   	data/list/ft_lst_map.c \
				   	data/list/ft_lst_new.c \
					data/list/ft_lst_remove.c \
					data/list/ft_lst_size.c \
					data/list/ft_lst_tadd.c \
					data/list/ft_lst_tget.c \
					data/list/ft_lst_tinsert.c \
					data/list/ft_lst_tlast.c \
					data/map/ft_map_clear.c \
					data/map/ft_map_contains.c \
					data/map/ft_map_destroy.c \
					data/map/ft_map_get.c \
					data/map/ft_map_new.c \
					data/map/ft_map_put.c \
					data/map/ft_map_remove.c \
					data/map/ft_map_size.c \
				   	io/get_next_line.c \
					math/ft_abs.c \
					math/ft_fabs.c \
					math/ft_fmax.c \
					math/ft_fmin.c \
					math/ft_fpow.c \
					math/ft_max.c \
					math/ft_min.c \
					math/ft_pow.c \
					math/ft_sqrt.c \
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
					string/atox/ft_atoi_base.c \
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
					string/strtox/ft_strtoi.c \
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
COPTS			= 	-march=native -fomit-frame-pointer -ftree-vectorize -ffast-math -fno-semantic-interposition -pipe -fPIC -I $(INCLUDE_DIR)

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
