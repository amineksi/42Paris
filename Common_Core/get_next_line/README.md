# get_next_line

Fonction permettant de lire un fichier **ligne par ligne** depuis un descripteur de fichier. Projet du tronc commun 42.

## Description

`get_next_line` lit une ligne à la fois depuis un fd (fichier, stdin, socket, etc.), sans connaître la taille à l’avance. Elle gère :

- Des buffers de taille configurable (`BUFFER_SIZE`)
- Plusieurs descripteurs simultanés (version bonus)
- Les fichiers vides et les lignes vides

## Compilation

```bash
make        # Compile get_next_line.a (version bonus avec multi-fd)
make clean
make fclean
make re
```

## Utilisation

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

- **Retour** : La ligne lue (avec `\n`), ou `NULL` en fin de fichier / erreur
- **fd** : Descripteur de fichier ouvert en lecture

## Version bonus

La version bonus gère plusieurs fichiers en parallèle en stockant un buffer par fd dans une liste chaînée.

## Fichiers

- `get_next_line.c` / `get_next_line_bonus.c` — Logique principale
- `get_next_line_utils.c` — Fonctions utilitaires (strjoin, strlen, etc.)
- `get_next_line.h` — Définition de `BUFFER_SIZE` et prototype
