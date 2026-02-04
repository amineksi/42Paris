# BSQ — Biggest Square

Algorithme trouvant le **plus grand carré vide** dans une carte contenant des obstacles. Projet d’algorithme de la Piscine 42.

## Description

BSQ analyse une carte (grille de caractères) et détermine le plus grand carré de cases vides, en évitant les obstacles. La solution utilise la **programmation dynamique** pour une complexité optimale.

### Format de la carte

- Première ligne : nombre de lignes, caractères représentant vide/obstacle/plein
- Lignes suivantes : la grille

Exemple :
```
9.ox
............................
....o.......................
............o...............
............................
....o.......................
...............o............
............................
......o..............o......
..o.......o................
```

## Compilation

> **Note** : Si le fichier s'appelle `Makefile.txt`, renommez-le en `Makefile` pour utiliser `make`.

```bash
make        # Crée l'exécutable bsq
make clean
make fclean
make re
```

## Utilisation

### Avec un fichier

```bash
./bsq map.txt
```

### Avec plusieurs fichiers

```bash
./bsq map1.txt map2.txt map3.txt
```

### Entrée standard

```bash
echo "4.ox
....
....
....
...." | ./bsq
```

### Générateur de cartes (Perl)

```bash
perl gen.sh <largeur> <hauteur> <densité> > map.txt
./bsq map.txt
```

**Exemple :** `perl gen.sh 20 20 5 > test.ber` génère une carte 20×20 avec ~5 % d’obstacles.

## Contraintes

- Taille maximale de la carte : **1023 × 1023**

## Architecture

- `bsq.c` — Point d’entrée
- `map.c` / `map_utils.c` — Lecture et parsing de la carte
- `read.c` — Gestion de l’entrée
- `solve.c` / `solve_utils.c` — Algorithme du plus grand carré

## Compétences

- Programmation dynamique
- Parsing de fichiers
- Algorithmes sur grilles
