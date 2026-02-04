# libft

Custom C library recreating standard libc functions and linked lists. Foundational project of the 42 Common Core.

## Description

`libft` is a reusable library that serves as the base for many other 42 projects (ft_printf, get_next_line, etc.). It implements:

- **Character functions**: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`
- **String functions**: `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup`, `substr`, `strjoin`, `strtrim`, `split`, `strmapi`, `striteri`
- **Memory functions**: `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`
- **Conversion functions**: `atoi`, `itoa`
- **Output functions**: `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`
- **Linked lists**: `lstnew`, `lstadd_front`, `lstadd_back`, `lstsize`, `lstlast`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

## Build

```bash
make        # Build libft.a
make clean  # Remove .o files
make fclean # Remove .o and libft.a
make re     # Full rebuild
```

## Usage

```c
#include "libft.h"

int main(void)
{
    char    *str = ft_strdup("Hello 42!");
    t_list  *lst = ft_lstnew(str);

    ft_putendl_fd(str, 1);
    ft_lstclear(&lst, free);
    return (0);
}
```

Link with `-lft -L.` when compiling your project.

## File Structure

- `libft.h` — Header with prototypes
- `*.c` — Function implementations (one function per file)
- `Makefile` — Build rules
