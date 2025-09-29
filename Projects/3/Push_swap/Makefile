CC       := cc
CFLAGS   := -Wall -Wextra -Werror -g
INCLUDES := -I includes -I printf/includes
LIBS     := -L printf/libft -L printf -lft -lftprintf
BUILD    := build
NAME     := push_swap

SRC_DIR  := src
OBJ_DIR  := $(BUILD)
SRC      := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ      := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT     := printf/libft/libft.a
LIBPRINTF := printf/libftprintf.a

all: $(BUILD) $(LIBFT) $(LIBPRINTF) $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(NAME): $(OBJ) $(LIBFT) $(LIBPRINTF)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)
	@echo "✅ Compilation success !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Assure la création des sous-dossiers dans build/
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	@echo "📦 Vérification de libft..."
	@make -C printf/libft bonus -s

$(LIBPRINTF): $(LIBFT)
	@echo "📦 Vérification de libftprintf..."
	@make -C printf all -s

clean:
	@echo "🧹 Removing objects..."
	@make -C printf/libft clean -s
	@make -C printf clean -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️ Deleting $(NAME)..."
	@make -C printf/libft fclean -s
	@make -C printf fclean -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
