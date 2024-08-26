# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2024/08/26 14:06:40 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Ensure tools are made available
MAKE			=	make --no-print-directory
PROVIDE_TARGETS	:=	./tools/provide-targets/provide-targets
_				:=	$(shell $(MAKE) -C tools/provide-targets >/dev/null 2>&1)

LIBNAME			=	ft
NAME			= 	lib$(LIBNAME)
LIBSHARE		= 	$(NAME).so
LIBSTATIC		= 	$(NAME).a

NO_LOG			?=	0
SHOW_CMDS		?=	0

ifeq ($(SHOW_CMDS), 0)
HIDE			=	@
endif

BUILD_FOLDER	= 	build
OUTPUT_FOLDER	= 	$(BUILD_FOLDER)/output

HOST			=	$(shell hostname | cut -d. -f2)
DEBUG			?=	0

SRC_FILES		=  	\
					data/hashmap/ft_map_clear.c \
					data/hashmap/ft_map_contains.c \
					data/hashmap/ft_map_free.c \
					data/hashmap/ft_map_get.c \
					data/hashmap/ft_map_keys.c \
					data/hashmap/ft_map_new.c \
					data/hashmap/ft_map_put.c \
					data/hashmap/ft_map_remove.c \
					data/hashmap/ft_map_size.c \
					data/list/ft_lst_add.c \
					data/list/ft_lst_clone.c \
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
					getopt/long/ft_opt_get_long.c \
					getopt/long/ft_opt_get_long_core.c \
					getopt/posix/ft_opt_get_posix.c \
					getopt/ft_opt_args.c \
					getopt/ft_opt_get.c \
					getopt/ft_opt_globals.c \
					getopt/ft_opt_msg.c \
					getopt/ft_opt_permute.c \
					getopt/ft_opt_reset.c \
				   	io/get_next_line.c \
					math/mat3d/ft_mat3d_identity.c \
					math/mat3d/ft_mat3d_mult.c \
					math/mat3d/ft_mat3d_rot.c \
					math/mat3d/ft_mat3d_rot_vec3d.c \
					math/mat3d/ft_mat3d_rot_x.c \
					math/mat3d/ft_mat3d_rot_y.c \
					math/mat3d/ft_mat3d_rot_z.c \
					math/mat3d/ft_mat3d_scale.c \
					math/vec2i/ft_vec2i.c \
					math/vec3d/ft_vec3d.c \
					math/vec3d/ft_vec3d_add.c \
					math/vec3d/ft_vec3d_clone.c \
					math/vec3d/ft_vec3d_cross.c \
					math/vec3d/ft_vec3d_div.c \
					math/vec3d/ft_vec3d_dot.c \
					math/vec3d/ft_vec3d_eq.c \
					math/vec3d/ft_vec3d_len.c \
					math/vec3d/ft_vec3d_mult.c \
					math/vec3d/ft_vec3d_mult_mat3d.c \
					math/vec3d/ft_vec3d_norm.c \
					math/vec3d/ft_vec3d_sub.c \
					math/vec3d/ft_vec3d_to_vec2i.c \
					math/ft_abs.c \
					math/ft_fabs.c \
					math/ft_fmax.c \
					math/ft_fmin.c \
					math/ft_fpow.c \
					math/ft_max.c \
					math/ft_min.c \
					math/ft_pow.c \
					math/ft_sqrt.c \
					mem/arena/ft_arena_alloc.c \
					mem/arena/ft_arena_clear.c \
					mem/arena/ft_arena_free.c \
					mem/arena/ft_arena_new.c \
				   	mem/ft_bzero.c \
				   	mem/ft_calloc.c \
				   	mem/ft_memchr.c \
				   	mem/ft_memcmp.c \
				   	mem/ft_memcpy.c \
				   	mem/ft_memmove.c \
				   	mem/ft_memset.c \
					mem/ft_realloc.c \
					print/printf/flag/pf_hash_mutator.c \
					print/printf/flag/pf_leftjustify_mutator.c \
					print/printf/flag/pf_padding_mutator.c \
					print/printf/flag/pf_precision_mutator.c \
					print/printf/str/pf_str_append.c \
					print/printf/str/pf_str_create.c \
					print/printf/str/pf_str_init.c \
					print/printf/type/pf_format_char.c \
					print/printf/type/pf_format_float.c \
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
					string/compare/ft_iscntrl.c \
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
					string/create/ft_strdup.c \
					string/create/ft_strdup_range.c \
					string/create/ft_strjoin.c \
					string/create/ft_strjoins.c \
					string/create/ft_strmapi.c \
					string/create/ft_strndup.c \
					string/create/ft_strnew.c \
					string/create/ft_strtrim.c \
					string/create/ft_substr.c \
					string/mutate/ft_stpcpy.c \
					string/mutate/ft_strcat.c \
					string/mutate/ft_strcpy.c \
					string/mutate/ft_strlcat.c \
					string/mutate/ft_strlcpy.c \
					string/mutate/ft_strncat.c \
					string/mutate/ft_strncpy.c \
					string/mutate/ft_strtolower.c \
					string/mutate/ft_strtoupper.c \
					string/mutate/ft_tolower.c \
					string/mutate/ft_toupper.c \
					string/query/ft_lllen.c \
					string/query/ft_lllen_base.c \
					string/query/ft_strall.c \
					string/query/ft_strany.c \
					string/query/ft_strchr.c \
					string/query/ft_strcspn.c \
					string/query/ft_striteri.c \
					string/query/ft_strlen.c \
					string/query/ft_strnstr.c \
					string/query/ft_strpbrk.c \
					string/query/ft_strrchr.c \
					string/query/ft_strspn.c \
					string/query/ft_strstr.c \
					string/query/ft_ulllen.c \
					string/query/ft_ulllen_base.c \
					string/strtox/ft_strtoi.c \
					string/strtox/ft_strtoi_base.c \
					string/strtox/ft_strtoll.c \
					string/xtoa/ft_lltoa.c \
					string/xtoa/ft_lltoa_base.c \
					string/xtoa/ft_ulltoa.c \
					string/xtoa/ft_ulltoa_base.c \
					string/ft_strdel.c \
					wchar/internal/ft_bittab.c \
					wchar/internal/ft_bittab_ranges.c \
					wchar/internal/ft_codeunit.c \
					wchar/internal/ft_illegal_sequence.c \
					wchar/internal/ft_wchar_oob.c \
					wchar/ft_mblen.c \
					wchar/ft_mbtowc.c

SRC_FOLDER		= 	src
SRC_FILES		:= 	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))

OBJ_CACHE		= 	$(BUILD_FOLDER)/objects
OBJ				= 	$(SRC_FILES:.c=.o)
OBJ_CACHE_FILES	:=	$(OBJ:$(SRC_FOLDER)/%.o=$(OBJ_CACHE)/%.o)

DEPS_FOLDER		= 	$(BUILD_FOLDER)/deps
DEPS			=	$(SRC_FILES:$(SRC_FOLDER)/%.c=$(DEPS_FOLDER)/%.d)

INCLUDE_DIR		= 	include

CC				=	clang
CFLAGS			= 	-Wall -Wextra -Werror
ifeq ($(DEBUG), 1)
CFLAGS			+= 	-g3
endif
DFLAGS 			=	-MT $@ -MMD -MP -MF $(DEPS_FOLDER)/$*.tmp.d

ARCH			=	native
ifeq ($(HOST),42angouleme)
ARCH			=	skylake
endif
ifeq ($(HOST),komet)
ARCH			=	znver2
endif
COPTS			= 	-march=$(ARCH) -ftree-vectorize -ffast-math -fno-semantic-interposition -funroll-loops -funsafe-math-optimizations -funwind-tables -fstrict-enums -fsplit-lto-unit -fvectorize -fsave-optimization-record -foptimization-record-file=$@.yml -pipe -fPIC -I $(INCLUDE_DIR)

LDFLAGS		=	-lm
ifneq (, $(shell which mold))
LDFLAGS			+= 	-fuse-ld=mold
endif

ifneq ($(DEBUG), 1)
LDFLAGS			+=	-Wl,-s
endif

AR				= 	ar rcs
RM				= 	rm -rf

# Pretty stuff

TPUT			:=	tput -Txterm-256color
_END			:=	$(shell $(TPUT) sgr0)
_BOLD			:=	$(shell $(TPUT) bold)
_GRAY			:=	$(shell $(TPUT) setaf 8)

_TOTAL			:=	$(shell $(PROVIDE_TARGETS) $(OBJ_CACHE_FILES) | sed 's/ /\n/g' | wc -l)
_TOTAL_LEN		:=	$(shell printf $(_TOTAL) | wc -m)
_CURRENT		=	0

#
# Rules
#

all:			$(NAME)

bonus:
	@$(MAKE)

-include $(DEPS)

$(NAME):		$(LIBSHARE) $(LIBSTATIC)
	@printf "🚀 Built $(_BOLD)libft$(_END) $(_GRAY)(./$(BUILD_FOLDER))$(_END)\n"

$(LIBSHARE):	$(OUTPUT_FOLDER)/$(LIBSHARE)

$(LIBSTATIC):	$(OUTPUT_FOLDER)/$(LIBSTATIC)

$(OUTPUT_FOLDER)/$(LIBSHARE):	$(OBJ_CACHE_FILES) | $(OUTPUT_FOLDER)
ifeq ($(NO_LOG), 0)
	@printf "Linking shared library\n"
endif
	$(HIDE)$(CC) -nostartfiles -shared -o $(OUTPUT_FOLDER)/$(LIBSHARE) $(OBJ_CACHE_FILES) $(LDFLAGS)

$(OUTPUT_FOLDER)/$(LIBSTATIC):	$(OBJ_CACHE_FILES) | $(OUTPUT_FOLDER)
ifeq ($(NO_LOG), 0)
	@printf "Linking static library\n"
endif
	$(HIDE)$(AR) $(OUTPUT_FOLDER)/$(LIBSTATIC) $(OBJ_CACHE_FILES)

$(OBJ_CACHE)/%.o:	$(SRC_FOLDER)/%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPS_FOLDER)/$*)
ifeq ($(NO_LOG), 0)
	$(eval _CURRENT=$(shell echo $$(($(_CURRENT)+1))))
	$(eval _PERCENTAGE=$(shell echo $$(($(_CURRENT)*100/$(_TOTAL)))))
	@printf "($(shell printf "% 3s" "$(_PERCENTAGE)")%%) $(shell printf "%*d/%d" $(_TOTAL_LEN) $(_CURRENT) $(_TOTAL)) Compiling $<\n"
endif
	$(HIDE)$(CC) $(DFLAGS) $(CFLAGS) $(COPTS) -c $< -o $@
	@# dumb fixes, see https://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
	@mv -f $(DEPS_FOLDER)/$*.tmp.d $(DEPS_FOLDER)/$*.d
	@touch $@

$(OBJ_CACHE):
	@mkdir -p $(OBJ_CACHE)

$(OUTPUT_FOLDER):
	@mkdir -p $(OUTPUT_FOLDER)

doc:
	$(HIDE)doxygen Doxyfile

test:
	make --no-print-directory -C tests valgrind

clean:
	$(HIDE)$(RM) $(OBJ_CACHE)
ifeq ($(NO_LOG), 0)
	@printf "🧹 Cleaned $(_BOLD)libft$(_END) $(_GRAY)(./$(OBJ_CACHE))$(_END)\n"
endif

# 🤓 yes it should depend on `clean` but it makes my output nicer so i don't care.
fclean:
	$(HIDE)$(RM) $(BUILD_FOLDER)
	$(HIDE)$(RM) $(LIBSHARE)
	$(HIDE)$(RM) $(LIBSTATIC)
ifeq ($(NO_LOG), 0)
	@printf "🧹 Cleaned $(_BOLD)libft$(_END) $(_GRAY)(./$(BUILD_FOLDER))$(_END)\n"
endif

re:				fclean
	$(HIDE)$(MAKE) -j$(shell nproc)

.PHONY:			all clean fclean re doc test bonus
