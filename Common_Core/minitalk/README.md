# minitalk

**Client/server** communication program using **Unix signals** (`SIGUSR1`, `SIGUSR2`). 42 Common Core project.

## Description

`minitalk` sends messages between two processes without using pipes, sockets, or files. Communication relies solely on:

- **SIGUSR1** and **SIGUSR2** to encode bits (0 and 1)
- Character encoding in binary (8 bits per character)
- PID exchange to establish the connection

## Build

```bash
make        # Build client and server (bonus version)
make clean
make fclean
make re
```

## Usage

**Terminal 1 — Server:**
```bash
./server
# Displays its PID, e.g.: 12345
```

**Terminal 2 — Client:**
```bash
./client 12345 "Your message here"
```

The server displays the received message.

## Prototypes

```c
// Server
./server
// Displays its PID and waits for messages

// Client
./client <PID> <message>
```

## Architecture

- `server.c` — Listens for signals, decodes bits, reconstructs characters
- `client.c` — Sends the message bit by bit via SIGUSR1/SIGUSR2
- Bonus version: Unicode support (extended characters)

## Skills

- Unix signals (`signal`, `kill`)
- Inter-process communication
- Binary encoding/decoding
- Process management (PID)
