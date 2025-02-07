NAME=get_next_line
CC = cc -Wall -Wextra -Werror
SRC=get_next_line.c get_next_line_utils.c
INC=get_next_line.h
OBJ=$(SRC:.c=.o)
SRCBNS=get_next_line_bonus.c get_next_line_utils_bonus.c
OBJBNS=$(SRCBNS:.c=.o)
INCBNS=get_next_line_bonus.h


all:
	$(CC) -c $(SRC) -D BUFFER_SIZE=35 -g
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJBNS)

fclean:
	rm -rf $(OBJ) $(OBJBNS) $(NAME)

bonus:
	$(CC) -c $(SRCBNS) -D BUFFER_SIZE=35 -g
	$(CC) $(OBJBNS) -o $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
