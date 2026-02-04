# get_next_line

Function to read a file **line by line** from a file descriptor. 42 Common Core project.

## Description

`get_next_line` reads one line at a time from an fd (file, stdin, socket, etc.) without knowing the size in advance. It handles:

- Configurable buffer size (`BUFFER_SIZE`)
- Multiple simultaneous descriptors (bonus version)
- Empty files and empty lines

## Build

```bash
make        # Build get_next_line.a (bonus version with multi-fd)
make clean
make fclean
make re
```

## Usage

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Prototype

```c
char *get_next_line(int fd);
```

- **Returns**: The read line (including `\n`), or `NULL` on EOF/error
- **fd**: File descriptor opened for reading

## Bonus Version

The bonus version handles multiple files in parallel by storing a buffer per fd in a linked list.

## Files

- `get_next_line.c` / `get_next_line_bonus.c` — Main logic
- `get_next_line_utils.c` — Utility functions (strjoin, strlen, etc.)
- `get_next_line.h` — `BUFFER_SIZE` definition and prototype
