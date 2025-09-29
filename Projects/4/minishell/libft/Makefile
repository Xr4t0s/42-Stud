# Fichiers sources
SRCS            = $(wildcard $(SRC_DIR)/*.c)
BONUS_SRCS      = $(wildcard $(SRC_BONUS_DIR)/*.c)

# Fichiers objets
OBJS            = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BONUS_OBJS      = $(patsubst $(SRC_BONUS_DIR)/%.c, $(OBJ_BONUS_DIR)/%.o, $(BONUS_SRCS))

# Dossiers
SRC_DIR         = src
SRC_BONUS_DIR   = src_bonus
OBJ_DIR         = obj
OBJ_BONUS_DIR   = obj_bonus

# Compilateur et flags
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -I.

# Nom de la librairie
NAME            = libft.a

# Commandes
RM              = rm -rf
MKDIR           = mkdir -p

# Règles
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	$(MKDIR) $(OBJ_BONUS_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilation des fichiers sources en objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_DIR) $(OBJ_BONUS_DIR) $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
