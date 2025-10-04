NAME	= phonebook
SRC		= src/main.cpp
INC		= -I includes
OBJ		= $(SRC:.cpp=.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX		= c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(INC) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CF) -I$(INC) -c $< -o $@

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean