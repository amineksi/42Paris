# so_long

Jeu 2D type labyrinthe développé avec **MiniLibX**. Le joueur doit collecter tous les objets avant d’atteindre la sortie. Projet du tronc commun 42.

## Description

`so_long` est un jeu graphique en C qui met en œuvre :

- **Rendu graphique** via MiniLibX (fenêtre, sprites, événements)
- **Parsing de cartes** au format `.ber` (texte)
- **Pathfinding** — vérification qu’un chemin valide existe (collectibles + sortie accessibles)
- **Gestion des touches** (WASD ou flèches) et fermeture propre

### Éléments de la carte

| Caractère | Rôle |
|-----------|------|
| `1` | Mur |
| `0` | Sol |
| `P` | Joueur (position de départ) |
| `C` | Collectible |
| `E` | Sortie |

## Prérequis

- **MiniLibX** (Linux) : `libmlx_linux.a` et headers dans `include/`
- **X11** : `libXext`, `libX11`
- **libft** : incluse dans le projet

## Compilation

```bash
make        # Compile l'exécutable so_long
make clean
make fclean
make re
```

## Utilisation

```bash
./so_long maps/valid.ber
```

### Format des cartes (.ber)

- Rectangulaires, entourées de murs
- Un seul `P`, un seul `E`, au moins un `C`
- Exemple minimal :

```
111111
1P0C01
1C00E1
111111
```

## Structure du projet

```
so_long/
├── src/           # Code source
│   ├── main.c
│   ├── creating_map.c   # Lecture et parsing
│   ├── drawing_map.c    # Rendu graphique
│   ├── handle_keys.c    # Gestion des entrées
│   ├── algo_path.c      # Vérification du chemin
│   └── ...
├── maps/          # Cartes de test
├── assets/        # Sprites XPM
├── libft/         # Bibliothèque personnalisée
└── include/       # Headers (mlx, libft)
```

## Compétences

- Programmation graphique (MiniLibX)
- Algorithmes de parcours (BFS/DFS pour le pathfinding)
- Gestion mémoire et libération propre
- Parsing et validation de données
