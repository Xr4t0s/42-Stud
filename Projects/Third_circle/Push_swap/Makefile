CC       := cc
CFLAGS   := -Wall -Wextra -Werror -g
INCLUDES := -I includes
LIBS     := -L libs -lft -lftprintf
BUILD    := build
NAME     := push_swap

SRC_DIR  := src
OBJ_DIR  := $(BUILD)
SRC      := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ      := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)
	@echo "✅ Compilation success !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@echo "🧹 Removing objects..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️ Deleting $(NAME)..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
