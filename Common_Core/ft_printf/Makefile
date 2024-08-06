NAME		= libftprintf.a
LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft
SRC			= ./files
SRC_FILES	= ft_printf.c ft_print_char.c ft_printf_utils.c ft_print_hexa.c ft_print_mem.c 
OBJS		= $(SRC_FILES:.c=.o)

CC			= cc 
AR			= ar rcs
RM			= rm -rf 
CFLAGS		= -Wall -Wextra -Werror
CP			= cp

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				cp $(LIBFT) $(NAME)
				ar rcs $(NAME) $(OBJS)

$(LIBFT):	$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)

%.o: 		$(SRC)/%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re