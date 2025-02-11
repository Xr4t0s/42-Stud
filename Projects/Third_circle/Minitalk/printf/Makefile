NAME = libftprintf.a
SRC = src/ft_printf.c src/utils*.c src/parsing.c src/init.c src/print_addr.c
OBJ = ft_printf.o utils*.o parsing.o init.o print_addr.o
INC = includes
CC = cc
CC_FLAG = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

all:	
	@$(CC) $(CC_FLAG) $(SRC) -c -I $(INC)/
	@$(AR) $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean:
	@rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)