NAME	= megaphone
SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX		= c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean