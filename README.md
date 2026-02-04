# 42Paris — Portfolio de projets C

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![42 School](https://img.shields.io/badge/42-Paris-00BABC.svg)](https://www.42.fr/)

Ce dépôt regroupe l'ensemble des projets réalisés dans le cadre du cursus **42 Paris** — une école d'informatique basée sur la pédagogie par projets et l'apprentissage pair-à-pair.

> **Objectif** : Ce portfolio est conçu pour présenter mes compétences en développement C lors de candidatures et entretiens techniques.

---

## 📋 Table des matières

- [Structure du projet](#-structure-du-projet)
- [Projets Common Core](#-projets-common-core)
- [Projets Piscine](#-projets-piscine)
- [Installation et utilisation](#-installation-et-utilisation)
- [Compétences démontrées](#-compétences-démontrées)
- [Licence](#-licence)

---

## 📁 Structure du projet

```
42Paris/
├── Common_Core/          # Projets du tronc commun 42
│   ├── libft/             # Bibliothèque C personnalisée
│   ├── ft_printf/         # Implémentation de printf
│   ├── get_next_line/     # Lecture ligne par ligne (fichiers/descripteurs)
│   ├── minitalk/          # Client/Serveur de communication (signaux Unix)
│   ├── so_long/           # Jeu 2D avec MiniLibX
│   └── Piscine_Reloaded/  # Exercices de révision C
├── 42Piscine/             # Projets réalisés pendant la Piscine
│   └── BSQ/               # Algorithme du plus grand carré
├── LICENSE
└── README.md
```

---

## 🎯 Projets Common Core

### [libft](Common_Core/libft/)
Bibliothèque C personnalisée recréant les fonctions standards (`string.h`, `stdlib.h`, etc.) ainsi que des listes chaînées.

**Compétences** : Manipulation mémoire, chaînes de caractères, structures de données.

### [ft_printf](Common_Core/ft_printf/)
Réimplémentation de la fonction `printf` avec gestion des conversions `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` et `%`.

**Compétences** : Variadiques, formatage, gestion des types.

### [get_next_line](Common_Core/get_next_line/)
Fonction permettant de lire un fichier ligne par ligne, y compris depuis un descripteur de fichier (stdin, socket, etc.).

**Compétences** : Gestion des buffers, allocation dynamique, I/O.

### [minitalk](Common_Core/minitalk/)
Programme client/serveur utilisant les **signaux Unix** (`SIGUSR1`, `SIGUSR2`) pour transmettre des messages entre processus.

**Compétences** : Communication inter-processus, signaux, encodage binaire.

### [so_long](Common_Core/so_long/)
Jeu 2D type labyrinthe développé avec **MiniLibX** (graphismes). Le joueur doit collecter tous les objets avant de sortir.

**Compétences** : Programmation graphique, algorithmes de parcours (pathfinding), gestion d’événements.

### [Piscine_Reloaded](Common_Core/Piscine_Reloaded/)
Exercices de révision C post-Piscine (manipulation de chaînes, pointeurs, etc.).

---

## 🏊 Projets Piscine

### [BSQ](42Piscine/BSQ/)
**Biggest Square** — Algorithme trouvant le plus grand carré vide dans une carte contenant des obstacles.

**Compétences** : Algorithmes, programmation dynamique, parsing.

---

## 🚀 Installation et utilisation

Chaque projet est autonome et possède son propre `Makefile`. Exemple :

```bash
# Compilation
cd Common_Core/libft && make

# Nettoyage
make fclean

# Recompilation complète
make re
```

Consultez le `README.md` de chaque sous-projet pour les instructions détaillées.

---

## 💡 Compétences démontrées

| Domaine | Projets concernés |
|---------|-------------------|
| **C pur** | libft, ft_printf, get_next_line, BSQ |
| **Structures de données** | libft (listes chaînées) |
| **Système (Unix)** | minitalk (signaux, processus) |
| **Graphisme** | so_long (MiniLibX) |
| **Algorithmes** | BSQ, so_long (pathfinding) |
| **Gestion mémoire** | Tous les projets |

---

## 📄 Licence

Ce projet est sous licence [MIT](LICENSE). Voir le fichier `LICENSE` pour plus de détails.

---

*Si ce portfolio vous a été utile, n'hésitez pas à laisser une ⭐ !*
