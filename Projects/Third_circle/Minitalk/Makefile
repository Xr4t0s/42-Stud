MAKEFLAGS	+= -s

SRV			:= server
CLI			:= client

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
LIBS		:= -L printf -L printf/libft -lft -lftprintf
INCL		:= -I includes -I printf/includes

SRC			:= src
BUILD		:= build
CLI_BUILD	:= $(BUILD)/$(CLI)
SRV_BUILD	:= $(BUILD)/$(SRV)
SRC_CLI_DIR	:= $(SRC)/$(CLI)
SRC_SRV_DIR	:= $(SRC)/$(SRV)

SRC_CLI		:= $(shell find $(SRC_CLI_DIR) -type f -name "*.c")
SRC_SRV		:= $(shell find $(SRC_SRV_DIR) -type f -name "*.c")
OBJ_CLI		:= $(patsubst $(SRC_CLI_DIR)/%.c,$(CLI_BUILD)/%.o,$(SRC_CLI))
OBJ_SRV		:= $(patsubst $(SRC_SRV_DIR)/%.c,$(SRV_BUILD)/%.o,$(SRC_SRV))

LIBFT       := printf/libft/libft.a
LIBPRINTF   := printf/libftprintf.a

all: $(BUILD) $(LIBFT) $(LIBPRINTF) $(SRV) $(CLI)

$(BUILD):
	@mkdir -p $(BUILD) $(CLI_BUILD) $(SRV_BUILD)

$(SRV): $(OBJ_SRV) $(LIBFT) $(LIBPRINTF)
	@echo "🔗  Linking $(SRV)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅  Compilation success !"

$(CLI): $(OBJ_CLI) $(LIBFT) $(LIBPRINTF)
	@echo "🔗  Linking $(CLI)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅  Compilation success !"

$(SRV_BUILD)/%.o: $(SRC_SRV_DIR)/%.c | $(BUILD)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

$(CLI_BUILD)/%.o: $(SRC_CLI_DIR)/%.c | $(BUILD)
	@echo "🛠️ Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

$(LIBFT):
	@make -C printf/libft bonus -s
	@touch $(LIBFT)


$(LIBPRINTF): $(LIBFT)
	@make -C printf all -s
	@touch $(LIBFT)

clean:
	@echo "🧹  Removing objects"
	@make -C printf/libft clean -s
	@make -C printf clean -s
	@rm -rf $(BUILD)

fclean: clean
	@echo "🗑️ Deleting libraries, $(SRV) and $(CLI)..."
	@make -C printf/libft fclean -s
	@make -C printf fclean -s
	@rm -f $(SRV) $(CLI)

re: fclean all

.PHONY: all clean fclean re
