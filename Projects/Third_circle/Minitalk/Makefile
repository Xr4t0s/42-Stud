SRV			:= server
CLI			:= client

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
LIBS		:= -L libs -lft -lftprintf
INCL		:= -I includes

SRC			:= src
BUILD		:= build
CLI_BUILD	:= $(BUILD)/$(CLI)
SRV_BUILD	:= $(BUILD)/$(SRV)
SRC_CLI_DIR	:= $(SRC)/$(CLI)
SRC_SRV_DIR	:= $(SRC)/$(SRV)

SRC_CLI		:= $(shell find $(SRC)/client -type f -name "*.c")
SRC_SRV		:= $(shell find $(SRC)/server -type f -name "*.c")
OBJ_CLI		:= $(patsubst $(SRC_CLI_DIR)/%.c,$(CLI_BUILD)/%.o,$(SRC_CLI))
OBJ_SRV		:= $(patsubst $(SRC_SRV_DIR)/%.c,$(SRV_BUILD)/%.o,$(SRC_SRV))

all: $(SRV) $(CLI)

$(SRV): $(OBJ_SRV)
	@echo "🔗 Linking $(SRV)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅ Compilation success !"

$(SRV_BUILD)/%.o: $(SRC_SRV_DIR)/%.c
	@mkdir -p $(SRV_BUILD)
	@echo "🛠️  Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL) $(LIBS)

$(CLI): $(OBJ_CLI)
	@echo "🔗 Linking $(CLI)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(LIBS)
	@echo "✅ Compilation success !"

$(CLI_BUILD)/%.o: $(SRC_CLI_DIR)/%.c
	@mkdir -p $(CLI_BUILD)
	@echo "🛠️  Compilation of $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL) $(LIBS)

clean:
	@echo "🧹 Removing objects..."
	@rm -rf $(BUILD)

fclean: clean
	@echo "🗑️  Deleting $(SRV) and $(CLI)..."
	@rm -rf $(SRV) $(CLI)

re: fclean all

.PHONY: all clean fclean re