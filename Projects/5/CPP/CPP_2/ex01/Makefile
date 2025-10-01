NAME    = towards
SRC     = 	main.cpp \
			src/Fixed.cpp
OBJ     = $(SRC:.cpp=.o)
CXX     = c++
CF      = -Wall -Wextra -Werror -std=c++98 -g
INC             = -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CF) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CF) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re