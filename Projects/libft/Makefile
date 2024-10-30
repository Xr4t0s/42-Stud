NAME =libft.a
SRC = ./*c
OBJ = ./*.o
AR =ar rcs
CC=cc
CFLAGS = -Wall -Wextra -Werror
INCL = .

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -g $(SRC) -I$(INCL)
	ar rcs $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re:
	rm -f $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCL)
	ar rcs $(NAME) $(OBJ)

.PHONY: all fclean clean re
