NAME	= phonebook
SRC		= src/main.cpp
INC		= -I includes
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX		= c++

all: $(NAME)

$(NAME):
	$(CXX) $(CFLAGS) $(INC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean