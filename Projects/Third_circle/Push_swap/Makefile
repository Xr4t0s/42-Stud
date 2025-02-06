SRC=src/errors/*.c \
	src/lists/instructions/*.c \
	src/lists/check_stacks/*.c \
	src/lists/delete_stacks/*.c \
	src/lists/create_stacks/*.c \
	src/push_swap/indexing/*.c \
	src/push_swap/costing/*c \
	src/push_swap/*c \
	src/utils/*.c \
	main.c

OBJ=build/*.o
NAME=push_swap
CC=cc -Wall -Wextra -Werror

all:
	$(CC) -c $(SRC) -I includes -g
	mkdir -p build
	mv *.o build/
	$(CC) -o $(NAME) $(OBJ) -I includes -L libs -lft -lftprintf -g

clean:
	rm -rf $(OBJ) build/

fclean: clean
	rm -rf $(NAME)

re: fclean all