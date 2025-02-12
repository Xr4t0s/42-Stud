NAME	:= fdf
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
INCL	:= -I includes
LIBS	:= -L libs -lft -lftprintf -lmlx
SRC_DIR	:= src
OBJ_DIR	:= build
SRC		:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT	:= libs/libft.a
PRINTF	:= libs/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@mkdir -p libs
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅ Compilation success !"

$(LIBFT):
	@echo "📦 Vérification de libft..."
	@make -C ./libft all -s
	@cp ./libft/libft.a $(LIBFT)

$(PRINTF): $(LIBFT)
	@echo "📦 Vérification de printf..."
	@make -C ./printf all -s
	@cp ./printf/libftprintf.a $(PRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	@echo "🧹 Deleting $(NAME) objects..."
	@make -C ./libft clean -s
	@make -C ./printf clean -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️ Deleting $(NAME) and objects..."
	@make -C ./libft fclean -s
	@make -C ./printf fclean -s
	@rm -rf $(NAME) libs

re: fclean all

.PHONY: all clean fclean re
