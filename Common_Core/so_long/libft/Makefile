# Name of the library
NAME = libft.a

# Source files for libft and ft_printf
FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_printf.c ft_print_char.c ft_printf_utils.c ft_print_hexa.c ft_print_mem.c

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Convert .c files to .o files
TO_FILES = $(FILES:.c=.o)

# Default rule to create .o files from .c files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the static library
$(NAME): $(TO_FILES)
	ar -rcs $@ $^

# All rule to create the main libft.a
all: $(NAME)

# Clean rule to remove object files
clean:
	rm -f $(TO_FILES)

# Full clean rule to remove object files and the static library
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
