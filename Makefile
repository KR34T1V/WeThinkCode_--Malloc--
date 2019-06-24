###############################################################################
#	Variables		#
###############################################################################

NAME = Malloc
AUTHOR = cterblan \| cterblan@student.wethinkcode.co.za

###############################################################################
#	SOURCES			#
###############################################################################

SRC = $(shell find . -name *.c)
OBJ := $(SRC:%.c=$(OBJ_DIR)%.o)

###############################################################################
#	FILE SORTING	#
###############################################################################

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes
LIB_DIR = lib

###############################################################################
#	COMPILER		#
###############################################################################

CC_FLAGS = Wall Werror Wextra
CC = gcc $(CC_FLAGS)

###############################################################################
#	LIBRARIES		#
###############################################################################

FT_PRINTF = $(LIB_DIR)/ft_printf


###############################################################################
#	RULES			#
###############################################################################

all: $(NAME)

$(NAME):

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

workspace:
	@touch author
	@echo $(AUTHOR) > author
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(INC_DIR)

###############################################################################
#	Specials	#
###############################################################################

.PHONEY := all clean fclean re workspace

.SILENT:

.PRECIOUS := author

###############################################################################
#	END			#
###############################################################################
