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
	@echo "🔗 Creation of $(NAME)..."
	@$(AR) $(NAME) $(OBJ)
	@echo "✅ Library $(NAME) successfully created !"

bonus: $(NAME) $(OBJ) $(OBJ_B)
	@echo "🔗  Adding bonus functions to $(NAME)..."
	@$(AR) $(NAME) $(OBJ_B)
	@echo "✅  Functions added successfully !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

$(OBJ_BNS_DIR)/%.o: $(SRC_BNS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️ Compilation of $< (bonus)..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	@echo "🧹 Deleting $(NAME) objects..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️ Deleting $(NAME) and objects..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
