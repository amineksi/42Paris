NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Iinclude -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

SRC_DIR = src
OBJ_DIR = obj
FILES = main init utils actions fork_utils other_utils routine 
SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re