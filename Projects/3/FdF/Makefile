NAME	:= fdf
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g
INCL	:= -I includes -I printf/includes
LIBS	:= -L minilibx -L printf/libft -L printf -lft -lftprintf -lmlx -lm -lXext -lX11
SRC_DIR	:= src
OBJ_DIR	:= build
SRC		:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT	:= printf/libft/libft.a
PRINTF	:= printf/libftprintf.a
MLX		:= minilibx/libmlx.a

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅ Compilation success !"

$(LIBFT):
	@echo "📦 Compiling libft..."
	@make -C printf/libft all bonus -s
	@echo "✅  Library libft.a successfully created !"

$(PRINTF): $(LIBFT)
	@echo "📦 Compiling ft_printf..."
	@make -C printf all -s
	@echo "✅  Library libftprintf.a successfully created !"

$(MLX):
	@echo "📦 Compiling minilibx..."
	@make -C minilibx all -s

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	@echo "🧹 Deleting objects..."
	@make -C printf/libft clean -s
	@make -C printf clean -s
	@make -C minilibx clean -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🧹 Deleting $(NAME) and objects..."
	@make -C printf/libft fclean -s
	@make -C printf fclean -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
