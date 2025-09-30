NAME    = zombie
SRC     = main.cpp \
          src/Zombie.cpp \
          src/newZombie.cpp \
		  src/randomChump.cpp
OBJ     = $(SRC:.cpp=.o)
INC     = includes
CXX     = c++
CF      = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CF) -I$(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CF) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
