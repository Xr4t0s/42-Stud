NAME        := cube3d

# Dossiers
SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := includes
LIBFT_DIR   := libft
LIBS_DIR    := libs

# Compilation
CC          := cc
CFLAGS      := -Wall -Wextra -g

# Système
UNAME_S     := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    MLX_DIR     := mlx_opengl
    MLX_FLAGS   := -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR     := mlx
    MLX_FLAGS   := -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

# Récupération des fichiers source
SRCS        := $(shell find $(SRC_DIR) -name "*.c")
OBJS        := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Commandes
RM          := rm -rf
MKDIR       := mkdir -p

# Règles principales
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -I$(LIBFT_DIR) $(MLX_FLAGS) \
		-L$(LIBFT_DIR) -lft -L$(LIBS_DIR) -lgnl -o $(NAME)

# Compilation .c vers .o avec création du dossier obj/ si nécessaire
$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Nettoyage
clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
