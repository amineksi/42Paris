# minitalk

Programme **client/serveur** de communication utilisant les **signaux Unix** (`SIGUSR1`, `SIGUSR2`). Projet du tronc commun 42.

## Description

`minitalk` permet d’envoyer des messages entre deux processus sans utiliser de pipes, sockets ou fichiers. La communication repose uniquement sur :

- **SIGUSR1** et **SIGUSR2** pour encoder les bits (0 et 1)
- Encodage des caractères en binaire (8 bits par caractère)
- Échange du PID pour établir la connexion

## Compilation

```bash
make        # Compile client et server (version bonus)
make clean
make fclean
make re
```

## Utilisation

**Terminal 1 — Serveur :**
```bash
./server
# Affiche son PID, par exemple : 12345
```

**Terminal 2 — Client :**
```bash
./client 12345 "Votre message ici"
```

Le serveur affiche le message reçu.

## Prototypes

```c
// Server
./server
// Affiche son PID et attend des messages

// Client
./client <PID> <message>
```

## Architecture

- `server.c` — Écoute les signaux, décode les bits, reconstruit les caractères
- `client.c` — Envoie le message bit par bit via SIGUSR1/SIGUSR2
- Version bonus : gestion de l’Unicode (caractères étendus)

## Compétences

- Signaux Unix (`signal`, `kill`)
- Communication inter-processus
- Encodage/décodage binaire
- Gestion des processus (PID)
