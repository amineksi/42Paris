SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc 
FLAGS = -Wall -Werror -Wextra 
NAME = ft_cat

${NAME}:	${OBJS}
		${CC} ${FLAGS} $^ -o $@

all : ${NAME}

.c.o :
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
		rm -rf ${OBJS}
fclean:		clean
		rm -f ${NAME}
re:	fclean all

.phony:	all clean fclean re