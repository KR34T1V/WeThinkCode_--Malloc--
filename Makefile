# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 11:24:40 by cterblan          #+#    #+#              #
#    Updated: 2019/07/23 22:55:44 by cterblan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								NAME
################################################################################
AUTHOR := cterblan

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME := libft_malloc_$(HOSTTYPE).so

################################################################################
#								DIRECTORIES
################################################################################

INC_DIR := inc
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib

################################################################################
#								FILES
################################################################################

SRC := malloc.c\
		free.c\
		realloc.c\
		show_alloc_mem.c\
		zone_find.c\
		zone_new.c\
		zone_type.c\
		zone_free.c\
		block_new.c\
		block_free.c
		
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

################################################################################
#								LIBRARIES
################################################################################
PRINTF_DIR := $(LIB_DIR)/libft
LIBFT_DIR := $(PRINTF_DIR)/lib/libft
LIB_FLAG := -lft

################################################################################
#								COMPILER
################################################################################

CFLAGS := -Wall -Werror -Wextra
CC := gcc $(CFLAGS)

################################################################################
#								RULES
################################################################################

all: update $(NAME)

$(NAME): $(OBJ)
	@make all -C $(PRINTF_DIR)/
	@echo "\033[35m\t\t[COMPILING] $@\033"
#	@#$(CC) -o $@ -I $(INC_DIR) -L $(LIBFT_DIR)/ $(LIB_FLAG) $(OBJ)
	@#COMPILE EXECUTABLE ^^^^^^
	@ar rcs $(NAME) $(OBJ) $(PRINTF_DIR)/obj/*.o $(LIBFT_DIR)/obj/*.o
	@#COMPILE LIBRARY ^^^^^^^
	@echo "\033[32m\t\t[COMPILED SUCCESSFULLY]\033"
	@ln -f $(NAME) libft_malloc.so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\033[36m\t\t[Building]\033[0m $@"
	@#norminette $<
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I $(INC_DIR) -o $@ -c $<
	@echo "\033[33m\t\t[SUCCESS]\033[0m"

clean: cleanlib
	@echo "\033[31m\t\t[CLEANING]\t$(OBJ_DIR)\033[0m"
	@rm -rf $(OBJ_DIR)

cleanlib:
	@echo "\033[31m\t\t[CLEANING]\t$(PRINTF_DIR)\033[0m"
	@make clean -C $(PRINTF_DIR)
	@#ADD ADDITIONAL LIBRARIES HERE ^^^

fclean: clean
	@echo "\033[31m\t\t[FCLEAN]\t$(NAME)\033[0m"
	@rm -f $(NAME) libft_malloc.so
	@#ADD ADDITIONAL NAME FILES HERE ^^^

fcleanlib:
	@echo "\033[31m\t\t[FCLEAN]\t$(LIB_DIR)]\033[0m"
	@make fclean -C $(PRINTF_DIR)
	@#ADD ADDITIONAL LIBRARIES HERE ^^^

re: fclean fcleanlib all

workspace:
	@echo "\033[36m\t\t[Building $@]\033[0m"
	@mkdir -p $(INC_DIR)
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(LIB_DIR)
	@touch author
	@echo $(AUTHOR) > author
update:
	git submodule update --recursive --remote
test: re
	@gcc src/main.c libft_malloc.so
	./a.out

################################################################################
#								SPECIAL
################################################################################

.PHONEY := all clean fclean re workspace
#ADD PHONEY HERE ^^^

#.SILENT:
#DON'T TOUCH ^^^

.PRECIOUS := author
#ADD PRECIOUS HERE ^^^