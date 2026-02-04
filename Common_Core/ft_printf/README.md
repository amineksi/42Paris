# ft_printf

Reimplementation of the libc `printf` function. 42 Common Core project.

## Description

`ft_printf` reproduces `printf` behavior for the following conversions:

| Specifier | Type | Description |
|-----------|------|-------------|
| `%c` | int | Character |
| `%s` | char * | String |
| `%p` | void * | Memory address (hexadecimal) |
| `%d` / `%i` | int | Signed integer |
| `%u` | unsigned int | Unsigned integer |
| `%x` | unsigned int | Hexadecimal lowercase |
| `%X` | unsigned int | Hexadecimal uppercase |
| `%%` | — | Literal `%` |

## Build

```bash
make        # Build libftprintf.a
make clean  # Remove object files
make fclean # Full clean
make re     # Full rebuild
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d, Hex: %x\n", "World", 42, 255);
    ft_printf("Pointer: %p\n", (void *)main);
    return (0);
}
```

## Dependencies

- **libft** — Library included in the project (subfolder `libft/`)

## Architecture

- `ft_printf.c` — Main function and format parsing
- `ft_print_*.c` — Handlers for each conversion type
- `ft_printf_utils.c` — Utility functions
