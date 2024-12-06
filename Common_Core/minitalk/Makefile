# Name of the executables
CLIENT = client
SERVER = server

# Bonus executables
BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.  # Include current directory for headers

# Source files
CLIENT_SRC = client.c
SERVER_SRC = server.c
BONUS_CLIENT_SRC = client_bonus.c
BONUS_SERVER_SRC = server_bonus.c

# Object files
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRC:.c=.o)
BONUS_SERVER_OBJS = $(BONUS_SERVER_SRC:.c=.o)

# Libft path
LIBFT = ./libft/libft.a

# Default target
all: $(LIBFT) $(CLIENT) $(SERVER)

# Bonus target
bonus: $(LIBFT) $(BONUS_CLIENT) $(BONUS_SERVER)

# Build libft
$(LIBFT):
	$(MAKE) -C libft

# Client executable
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(LIBFT)

# Server executable
$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(LIBFT)

# Bonus Client executable
$(BONUS_CLIENT): $(BONUS_CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(BONUS_CLIENT_OBJS) $(LIBFT)

# Bonus Server executable
$(BONUS_SERVER): $(BONUS_SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(BONUS_SERVER_OBJS) $(LIBFT)

# Compile .c files to .o files
%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	$(MAKE) -C libft clean
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(BONUS_CLIENT_OBJS) $(BONUS_SERVER_OBJS)

# Full clean: clean and remove executables
fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re