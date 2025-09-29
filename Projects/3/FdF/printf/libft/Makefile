NAME		:= libft.a
AR			:= ar rcs
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCL		:= -I includes
SRC_DIR		:= src
OBJ_DIR		:= build
SRC_BNS_DIR	:= $(SRC_DIR)/bonus
OBJ_BNS_DIR	:= $(OBJ_DIR)/bonus

SRC			:= $(shell find $(SRC_DIR) -type f -name "*.c" ! -name "*bonus.c")
OBJ			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

SRC_B		:= $(shell find $(SRC_BNS_DIR) -type f -name "*bonus.c")
OBJ_B		:= $(patsubst $(SRC_BNS_DIR)/%.c,$(OBJ_BNS_DIR)/%.o,$(SRC_B))

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	@$(AR) $(NAME) $(OBJ_B)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

$(OBJ_BNS_DIR)/%.o: $(SRC_BNS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
