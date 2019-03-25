# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/03/25 18:27:09 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

#CFLAGS = $(DFLAGS)

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################

MASTER		= srcs/

MAIN_FOLD = inout maths mem strings structures terminal big
MAIN_FOLD = srcs

HEAD_DIR = ./includes/

HEADERS	=	ft_printf.h\
			libft.h\
			time_exe.h

AUTO_HEAD	= auto.h

DIR_OBJ = ./objs/

MOVE_IT	=	$(MAIN_FOLD:%=$(MASTER)%)

##########################
##						##
##	 IMPORTANT FILES	##
##						##
##########################

# DIR_OBJ = ./objs/
HEADERS		+=	$(AUTO_SRC)\
				$(AUTO_HEAD)

AUTO_SEAD	=	$(HEAD_DIR)$(AUTO_SRC)
AUTO_PEAD	=	$(HEAD_DIR)$(AUTO_HEAD)


IF_FOLDS	=	$(MAIN_FOLD:%=find $(MASTER) -xdev -type d | cut -s -d '/' -f 2 | sort -u)
IF_FOLDS	=	$(shell ls $(MASTER) | grep objs)
IFOBJDIR	=	$(shell ls | grep objs)

DIR_SCRIPT	=	./scripts/

SRC_SCRIPT	=	get_protos.sh\
				get_mk_srcs.sh\
				get_master_head.sh

PAT_SCRIPT	=	$(SRC_SCRIPT:%=$(DIR_SCRIPT)%)

DIR_MK_DEP	=	./mk_dependencies

mk_d		= 	$(DIR_MK_DEP)/DIR/
mk_s		= 	$(DIR_MK_DEP)/SRC/
mk_p		= 	$(DIR_MK_DEP)/PAT/

mk_all		=	$(mk_d) $(mk_s) $(mk_p)

AUTO_DIR	=	auto/
AUTO_PAT	=	$(HEAD_DIR)$(AUTO_DIR)

MUST		=	$(DIR_OBJ)\
				$(DIR_SCRIPT) $(PAT_SCRIPT)\
				$(AUTO_PAT)

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

AUTO_SRC	= $(MAIN_FOLD:%=$(AUTO_DIR)auto_%.h)

HEADERS		=	$(HEADS:%=$(HEAD_DIR)%)

update_head	=	$(MAIN_FOLD:%=sh $(DIR_SCRIPT)get_protos.sh % $(MASTER);)
update_dep	=	$(MAIN_FOLD:%=sh $(DIR_SCRIPT)get_mk_srcs.sh % $(MASTER);)

include_dir	=	$(MAIN_FOLD:%=$(mk_d)dir_%.mk)
include_pat	=	$(MAIN_FOLD:%=$(mk_p)pat_%.mk)
include_src	=	$(MAIN_FOLD:%=$(mk_s)src_%.mk)

include_dep	= $(include_src) $(include_pat) $(include_dir)

SRC =
PAT =
DIR =

DIR_OBJ = ./objs/
IF_FOLDS	=	$(shell find $(MASTER) -xdev -type d | cut -s -d '/' -f 3 | sort -u)
IF_REF		=	$(shell echo "$(MAIN_FOLD)" | tr " " "\n" | sort)
IF_REF		=	$(shell echo "$(MAIN_FOLD)" | tr " " "\n" | sort)

ifeq ("$(IF_FOLDS)","$(IF_REF)")
include $(include_dep)
endif


OBJ = $(PAT:%.c=%.o)
OBJS = $(PAT:%.c=$(DIR_OBJ)%.o)
# $(shell echo $(OBJS))

MSG ?= Makefile automated push
##########################
##						##
##		 COLORS			##
##						##
##########################

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :		$(NAME)

$(NAME):	Makefile $(PAT) $(OBJS) $(HEAD)
			@$(call run_and_test, ar -rcs $(NAME) $(OBJS))

$(DIR_OBJ)%.o:%.c
			@$(call run_and_test, $(CC) $(CFLAGS) -I$(HEAD_DIR) -o $@ -c $<)

clean :
	@rm -f $(OBJS)
	@echo "\$(YELLOW)$(NAME) objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

re : fclean all

k:
	@echo $(IF_FOLDS)
	@echo $(IF_REF)

##############################################################################
##############################################################################
##																			##
##									-----									##
##									BONUS									##
##									-----									##
##																			##
##############################################################################
##############################################################################

git :
		@git add -A
		@git status
		git commit -am "$(MSG)"
		@git push

# file			:
# 					$(make) $(DIR_MK_DEP)
# 					$(make) $(mk_all)
# 					$(make) $(DIR_OBJ)
# 					$(make) $(AUTO_PAT)
# 					$(make) $(AUTO_SEAD)
# 					$(make) $(AUTO_PEAD)
#
# rand			:
# 					@rm -rf $(DIR_MK_DEP)
# 					@mkdir $(DIR_MK_DEP)
# 					@rm -rf $(mk_d) $(mk_s) $(mk_p)
# 					@mkdir $(mk_d) $(mk_s) $(mk_p)
# 					@$(update_dep)
# 					@rm -rf $(DIR_OBJ)
# 					@mkdir $(DIR_OBJ)
# 					@find $(MASTER) -type d -exec mkdir $(DIR_OBJ){} \;
# 					@rm -rf $(AUTO_PAT)
# 					@mkdir $(AUTO_PAT)
# 					@$(update_head)
# 					@sh scripts/get_master_head.sh $(HEAD_DIR)


$(PAT)			:	$(mk_all) $(DIR_OBJ) $(AUTO_PAT) $(AUTO_PEAD)


$(DIR_OBJ)		:
					@rm -rf $(DIR_OBJ)
					@mkdir $(DIR_OBJ)
					@rm -rf $(DIR_OBJ)/*
					@find $(MASTER)$(MAIN_FOLD) -type d -exec mkdir objs/{} \;
					@mv -f $(DIR_OBJ)$(MASTER)* $(DIR_OBJ)
					@rm -rf $(DIR_OBJ)$(MASTER)

$(AUTO_PAT)		:	$(AUTO_PEAD)
					@mkdir $(AUTO_PAT)
					@$(update_head)
					@sh scripts/get_master_head.sh $(HEAD_DIR)

$(AUTO_PEAD)	:
					@$(update_head)
					@sh scripts/get_master_head.sh $(HEAD_DIR)

$(mk_all)		:	$(DIR_MK_DEP)
					@rm -rf $(mk_d) $(mk_s) $(mk_p)
					@mkdir $(mk_d) $(mk_s) $(mk_p)
					@$(update_dep)

$(DIR_MK_DEP)	:
					@rm -rf $(DIR_MK_DEP)
					@mkdir $(DIR_MK_DEP)

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh


##########################
##						##
##		 PROTEC			##
##						##
##########################


##########################
##						##
##		 .PHONY			##
##						##
##########################
FORCE:

.PHONY : all clean fclean re git file object_ready check FORCE
