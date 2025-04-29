# Dossiers
SRC_DIR         = src
OBJ_DIR         = obj
LIBFT_DIR       = libft
LIBFT_A         = $(LIBFT_DIR)/libft.a

# Fichiers sources
SRCS            = $(shell find $(SRC_DIR) -name "*.c")
OBJS            = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nom du programme final
NAME            = minishell

# Compilateur et flags
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

# Commandes
RM              = rm -rf
MKDIR           = mkdir -p

# Règles
all: $(LIBFT_A) $(OBJ_DIR) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Pour recréer l'arborescence dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

bonus: all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
