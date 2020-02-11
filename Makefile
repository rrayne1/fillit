NAME = fillit
SRC = src/main.c src/fillit1.c src/fillit2.c src/fillit3.c src/fillit4.c src/fillit5.c
OBJ = main.o fillit1.o fillit2.o fillit3.o fillit4.o fillit5.o
INCLUDES = includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBPATH = libft/libft.a
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIBPATH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
