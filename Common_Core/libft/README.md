# libft

Bibliothèque C personnalisée recréant les fonctions standards de la libc ainsi que des structures de données (listes chaînées). Projet fondateur du tronc commun 42.

## Description

`libft` est une bibliothèque réutilisable qui sert de base à de nombreux autres projets 42 (ft_printf, get_next_line, etc.). Elle implémente :

- **Fonctions sur les caractères** : `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`
- **Fonctions sur les chaînes** : `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup`, `substr`, `strjoin`, `strtrim`, `split`, `strmapi`, `striteri`
- **Fonctions mémoire** : `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`
- **Fonctions de conversion** : `atoi`, `itoa`
- **Fonctions d’écriture** : `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`
- **Listes chaînées** : `lstnew`, `lstadd_front`, `lstadd_back`, `lstsize`, `lstlast`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

## Compilation

```bash
make        # Compile libft.a
make clean  # Supprime les .o
make fclean # Supprime .o et libft.a
make re     # Recompile depuis zéro
```

## Utilisation

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

Lier avec `-lft -L.` lors de la compilation de votre projet.

## Structure des fichiers

- `libft.h` — En-tête avec les prototypes
- `*.c` — Implémentations des fonctions (une fonction par fichier)
- `Makefile` — Règles de compilation
