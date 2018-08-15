NAME="lem-in"

#PATHS
SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/

#Source
SRC_NAME=	get_next_line.c \
			main.c \
			movement.c \
			parser.c \
			play.c \

OBJ_NAME = $(SRC_NAME:%.c=%.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

LDFLAGS = -L ./libft/

LFT = -lft

all:$(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	#@make -C./libft/
	@$(CC) -o $@  $(OBJ) $(LDFLAGS) $(LFT) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_PATH) 2> /dev/null || true

cleanlib:
	@make clean -C ./libft/

fclean: clean fcleanlib
	@rm -f $(NAME)

fcleanlib:
	@make fclean -C ./libft/

re : fclean all
