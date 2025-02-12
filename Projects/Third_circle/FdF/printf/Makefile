NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs
INC         := includes
SRC_DIR     := src
OBJ_DIR     := build
LIB_DIR     := libs
LIBFT       := $(LIB_DIR)/libft.a
SRC         := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) | $(LIB_DIR)
	@if [ ! -f $(NAME) ]; then \
		echo "🔗  Creation of $(NAME)..."; \
		$(AR) $(NAME) $(OBJ); \
		echo "✅  Library $(NAME) successfully created !"; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC) -L $(LIB_DIR) -lft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(LIBFT): | $(LIB_DIR)
	@echo "📦  Checking libft..."
	@make -C ./libft bonus -s
	@cp ./libft/libft.a $(LIBFT)

clean:
	@echo "🧹  Deleting $(NAME) objects..."
	@make -C ./libft clean -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️ Deleting $(NAME) and objects..."
	@make -C ./libft fclean -s
	@rm -rf $(LIB_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
