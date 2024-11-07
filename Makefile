# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2024/11/07 01:08:43 by kiroussa         ###   ########.fr        #
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

include sources.mk

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
COPTS			= 	-march=$(ARCH) -O3 -msse3 -mavx2 -ftree-vectorize -ffast-math -fno-math-errno -fno-semantic-interposition -funroll-loops -funsafe-math-optimizations -funwind-tables -fstrict-enums -fsplit-lto-unit -fvectorize -fsave-optimization-record -foptimization-record-file=$@.yml -pipe -fPIC -I $(INCLUDE_DIR)

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
