NAME=philo
CC=gcc
FLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = philo.c util.c util_1.c main.c
all : $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

fclean: clean
	rm -f $(NAME) $(NAMEB)

clean:
	rm -f *.o

re: fclean all
.PHONY: fclean clean re all