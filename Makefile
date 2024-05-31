CC=cc
CFLAGS= -Wall -Wextra -Werror
LFLAGS= -Llibft -lft
SRC= server.c client.c
OBJ=$(SRC:%.c=%.o)
NAME=libminitalk.a

$(NAME): $(SRC) minitalk.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)
	cd libft && $(MAKE)
	$(CC) -o server server.c $(NAME) $(LFLAGS)
	$(CC) -o client client.c $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f server
	rm -f client
	cd libft && $(MAKE) fclean

all: $(NAME)

re: fclean all