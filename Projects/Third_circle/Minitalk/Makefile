SERV=server
CLI=client
CC=cc -g
SRC=src/
SRCSERV=server.c
SERVOBJ=$(SRCSERV:.c=.o)
SRCCLI=client.c
CLIOBJ=$(SRCCLI:.c=.o)

all:
	$(CC) $(SRC)$(SRCSERV) -I includes -L libs -lft -lftprintf -o server -g
	$(CC) $(SRC)$(SRCCLI) -I includes -L libs -lft -lftprintf -o client -g

server:
	$(CC) $(SRC)$(SRCSERV) -I includes -Llibs -lft -lftprintf -o client

client:
	$(CC) $(SRC)$(SRCCLI) -I includes -Llibs -lft -lftprintf -o client

clean:
	rm client server -rf

fclean: clean

re: fclean all
