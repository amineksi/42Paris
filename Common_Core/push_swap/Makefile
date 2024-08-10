NAME = push_swap.a
FILES = 
CC = cc
CFLAGS = -Wall -Werror -Wextra -c -I.
TO_FILES = $(FILES:.c=.o)
TO_BONUS_FILES = $(BONUS_FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(TO_FILES)
	ar -rcs $@ $^

all: $(NAME)

bonus : $(TO_BONUS_FILES)
	@ar r $(NAME) $^
clean:
	rm -f $(TO_FILES) $(TO_BONUS_FILES) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
