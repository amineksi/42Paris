NAME = libft.a

FILES = mem/ft_memset.c mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memchr.c mem/ft_memcmp.c \
	str/ft_strlen.c is/ft_isalpha.c is/ft_isdigit.c is/ft_isalnum.c is/ft_isascii.c is/ft_isprint.c str/ft_toupper.c \
	str/ft_tolower.c str/ft_strchr.c str/ft_strrchr.c str/ft_strncmp.c str/ft_strlcpy.c str/ft_strlcat.c str/ft_strnstr.c \
	str/ft_atoi.c mem/ft_calloc.c str/ft_strdup.c str/ft_substr.c str/ft_strjoin.c str/ft_strtrim.c str/ft_split.c str/ft_itoa.c \
	str/ft_strmapi.c str/ft_striteri.c put/ft_putchar_fd.c put/ft_putstr_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \
	lst/ft_lstnew.c lst/ft_lstadd_front.c lst/ft_lstsize.c lst/ft_lstlast.c lst/ft_lstadd_back.c lst/ft_lstdelone.c \
	lst/ft_lstclear.c lst/ft_lstiter.c lst/ft_lstmap.c \
	printf/ft_printf.c printf/ft_print_char.c printf/ft_printf_utils.c printf/ft_print_hexa.c printf/ft_print_mem.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

TO_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(TO_FILES)
	ar -rcs $@ $^

all: $(NAME)

clean:
	rm -f $(TO_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
