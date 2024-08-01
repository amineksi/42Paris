SRCS = main.c ft_display_file.c
OBJS = $(SRCS:.c=.o)
CC = gcc 
FLAGS = -Wall -Werror -Wextra 
NAME = ft_display_file

${NAME}:	${OBJS}
		${CC} ${FLAGS} $^ -o $@

.c.o :
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all : ${NAME}
clean:
		rm -rf ${OBJS}
fclean:		clean
		rm -f ${NAME}

.phony:	all clean fclean re