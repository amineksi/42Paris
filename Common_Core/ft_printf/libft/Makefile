NAME = libft.a
FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c
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
