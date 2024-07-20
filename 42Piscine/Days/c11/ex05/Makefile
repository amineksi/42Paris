NAME = do-op
SRC = main.c converting.c operations.c
OBJS = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all:	${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} $^ -o $@

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		rm -rf ${OBJS}
fclean:		clean
		rm -f ${NAME}
re:	fclean all

.PHONY:	all clea fclean re