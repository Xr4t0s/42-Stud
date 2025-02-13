NAME	:= fdf
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g
INCL	:= -I includes -I printf/includes
LIBS	:= -L printf/libft -L printf -lft -lftprintf -lmlx -lm -lXext -lX11
SRC_DIR	:= src
OBJ_DIR	:= build
SRC		:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT	:= printf/libft/libft.a
PRINTF	:= printf/libftprintf.a

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅ Compilation success !"

$(LIBFT):
	@echo "📦 Vérification de libft..."
	@make -C printf/libft all bonus -s

$(PRINTF): $(LIBFT)
	@echo "📦 Vérification de printf..."
	@make -C printf all -s

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	@echo "🧹 Deleting $(NAME) objects..."
	@make -C printf/libft clean -s
	@make -C printf clean -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️ Deleting $(NAME) and objects..."
	@make -C printf/libft fclean -s
	@make -C printf fclean -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
