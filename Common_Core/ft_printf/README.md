# ft_printf

Réimplémentation de la fonction `printf` de la libc. Projet du tronc commun 42.

## Description

`ft_printf` reproduit le comportement de `printf` pour les conversions suivantes :

| Spécificateur | Type | Description |
|---------------|------|-------------|
| `%c` | int | Caractère |
| `%s` | char * | Chaîne de caractères |
| `%p` | void * | Adresse mémoire (hexadécimale) |
| `%d` / `%i` | int | Entier signé |
| `%u` | unsigned int | Entier non signé |
| `%x` | unsigned int | Hexadécimal minuscules |
| `%X` | unsigned int | Hexadécimal majuscules |
| `%%` | — | Caractère `%` |

## Compilation

```bash
make        # Compile libftprintf.a
make clean  # Supprime les objets
make fclean # Nettoyage complet
make re     # Recompilation complète
```

## Utilisation

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d, Hex: %x\n", "World", 42, 255);
    ft_printf("Pointer: %p\n", (void *)main);
    return (0);
}
```

## Dépendances

- **libft** — Bibliothèque incluse dans le projet (sous-dossier `libft/`)

## Architecture

- `ft_printf.c` — Fonction principale et parsing du format
- `ft_print_*.c` — Handlers pour chaque type de conversion
- `ft_printf_utils.c` — Fonctions utilitaires
