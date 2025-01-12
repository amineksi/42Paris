NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = include
MINILIBX = $(MINILIBX_DIR)/libmlx_linux.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Iinclude -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

LFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx_linux -lXext -lX11 -lm

SRC_DIR = src
OBJ_DIR = obj
FILES = end_of_game algo_utils creating_map freeing map_conditions algo_path checking_fcts drawing_map handle_keys main check_utils
SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re