# Variables
NAME	:= philo
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g
INC		:= -I includes -I libft/includes
LIBS	:= -L libft -lft
SRC_DIR	:= src
OBJ_DIR	:= obj

SRC := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C libft
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C libft
	rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


