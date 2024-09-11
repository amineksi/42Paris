NAME = push_swap
FILES = actions/push.c actions/reverse_rotate.c actions/rotate.c actions/swap.c algorithms/algo.c files/push_swap.c utils/move_nodes_functions.c utils/init_nodes_functions.c utils/check_functions.c utils/free_functions.c utils/initialize_stack_a.c utils/stack_functions.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstlast.c libft/ft_lstnew.c libft/ft_lstsize.c
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