
NAME = push_swap

SRC_DIR = srcs/

SRC = srcs/push_swap.c srcs/operations.c srcs/utile.c srcs/check_error.c srcs/algo.c srcs/sort_a.c srcs/main.c
	  
INC = includes/

LIBINC = libft/includes/

LIB = libft.a

BIN_DIR = bin/

BIN = push_swap.o operations.o utile.o check_error.o algo.o sort_a.o main.o

CC = gcc

OPTS = -Wall -Werror -Wextra -g

# *********************************RULES***************************************#

all			:  $(NAME)

$(NAME)		: 
	make -C libft/
	$(CC) $(OPTS) -I $(LIBINC) -I includes/ -c $(SRC)
	$(CC) $(OPTS) $(BIN) -L libft/ -lft -o $(NAME)


clean 		:
	make clean -C libft/
	rm -f $(BIN)

fclean		: clean
	make fclean -C libft/
	rm -f $(NAME)

re			: fclean all 