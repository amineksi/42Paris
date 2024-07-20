SRCS = bsq.c map.c solve.c read.c map_utils.c solve_utils.c
SRCS_DIR = srcs/
INCLUDES_DIR = includes/
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
CC = gcc 
FLAGS = -Wall -Werror -Wextra -g3 -I
NAME = bsq

${NAME}:	${OBJS}
		${CC} ${FLAGS} -c= $^ -o $@

all : ${NAME}

.c.o :
	$(CC) $(FLAGS) ${INCLUDES_DIR} -c $< -o ${<:.c=.o}

clean:
		rm -rf ${OBJS}
fclean:		clean
		rm -f ${NAME}
re:	fclean all

.phony:	all clean fclean re