NAME=get_next_line
CC = cc -Wall -Wextra -Werror
SRC=get_next_line.c get_next_line_utils.c
INC=get_next_line.h
OBJ=$(SRC:.c=.o)

all:
	$(CC) -c $(SRC) -D BUFFER_SIZE=35 -g
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all
