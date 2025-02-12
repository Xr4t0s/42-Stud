NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs
INC         := includes
SRC_DIR     := src
OBJ_DIR     := build
LIBFT       := libft/libft.a
SRC         := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@if [ ! -f $(NAME) ]; then \
		echo "🔗  Creation of $(NAME)..."; \
		$(AR) $(NAME) $(OBJ); \
		echo "✅  Library $(NAME) successfully created !"; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC) -L libft -lft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "📦 Vérification de libft..."
	@make -C libft bonus -s
	@touch $(LIBFT)

clean:
	@echo "🧹  Deleting $(NAME) objects..."
	@make -C libft clean -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️  Deleting $(NAME) and objects..."
	@make -C libft fclean -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
