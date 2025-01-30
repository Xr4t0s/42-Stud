SRC=src/errors/*.c src/lists/*c src/lists/manipulate_stacks/*.c src/utils/*.c main.c
OBJ=build/*.o
NAME=push_swap
CC=cc -Wall -Wextra -Werror

all:
	$(CC) -c $(SRC) -I includes -L libs -lft -lftprintf -g 
	mv *.o build/
	$(CC) -o $(NAME) $(OBJ) -I includes -L libs -lft -lftprintf -g

clean:
	rm -rf $(OBJ) build/

fclean: clean
	rm -rf $(NAME)

re: fclean all