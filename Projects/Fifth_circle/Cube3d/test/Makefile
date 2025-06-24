NAME = test

SRC = main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lX11 -lXext -lXpm -lm

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(NAME)

