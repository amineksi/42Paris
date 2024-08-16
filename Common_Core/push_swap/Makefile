NAME = push_swap
FILES = files/push_swap.c algorithms/algo.c utils/stack_functions.c algorithms/simple_alg.c libft/ft_atoi.c libft/ft_isdigit.c utils/check_functions.c actions/push.c libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstsize.c actions/swap.c utils/free_functions.c actions/reverse_rotate.c actions/rotate.c
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJ_FILES = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
