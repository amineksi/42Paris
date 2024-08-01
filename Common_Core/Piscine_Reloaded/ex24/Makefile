NAME = libft.a
SRC = srcs/
INCLUDES = ./includes
FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
CC = cc
FLAGS = -Wall -Werror -Wextra -c -I
TO_SRC =  $(addprefix $(SRC), $(FILES:.c=.o))

.c.o :
	$(CC) $(FLAGS) $(INCLUDES) $< -o ${<:.c=.o}
${NAME} : $(TO_SRC)
	ar -rcs $@ $^
all : ${NAME}
clean :
	rm -f $(TO_SRC)
fclean :
	rm -f $(NAME) $(TO_SRC)
re : fclean all

.phony : all clean fclean re