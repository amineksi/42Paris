# 42Paris — Project Portfolio

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![42 School](https://img.shields.io/badge/42-Paris-00BABC.svg)](https://www.42.fr/)

This repository contains all projects completed as part of the **42 Paris** curriculum — a project-based coding school using peer learning.

> **Purpose** : This portfolio showcases my skills in development (C, C++, systems, networking, DevOps, Linux administration) for job applications and technical interviews.

---

## 📋 Table of Contents

- [Project Structure](#-project-structure)
- [Common Core Projects](#-common-core-projects)
- [Piscine Projects](#-piscine-projects)
- [Installation & Usage](#-installation--usage)
- [Skills Demonstrated](#-skills-demonstrated)
- [License](#-license)

---

## 📁 Project Structure

```
42Paris/
├── Common_Core/          # 42 Common Core projects
│   ├── libft/             # Custom C library
│   ├── ft_printf/         # printf implementation
│   ├── get_next_line/     # Line-by-line reading (files/descriptors)
│   ├── minitalk/          # Client/Server (Unix signals)
│   ├── so_long/           # 2D game with MiniLibX
│   ├── push_swap/         # Stack sorting with constraints
│   ├── cub3d/             # 3D raycasting game (Wolfenstein-style)
│   ├── minishell/         # Command interpreter (bash-like)
│   ├── ft_irc/            # IRC server in C++
│   ├── inception/        # Docker stack (WordPress, MariaDB, Nginx)
│   ├── netpractice/       # Network configuration exercises
│   ├── born2beroot/       # Debian VM setup (SSH, sudo, firewall)
│   ├── cpp00 → cpp09/     # C++ modules (OOP, templates, STL...)
│   └── Piscine_Reloaded/  # C revision exercises
├── 42Piscine/             # Projects from the Piscine
│   ├── BSQ/               # Biggest square algorithm
│   ├── Days/              # C exercises (c00 to c10)
│   ├── Rush/              # Group projects (rush00, rush01)
│   └── Shell/             # Shell scripts (shell01)
├── LICENSE
└── README.md
```

---

## 🎯 Common Core Projects

### [libft](Common_Core/libft/)
Custom C library recreating standard libc functions and linked lists.

**Skills** : Memory manipulation, strings, data structures.

### [ft_printf](Common_Core/ft_printf/)
Reimplementation of `printf` with support for `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` and `%` conversions.

**Skills** : Variadic functions, formatting, type handling.

### [get_next_line](Common_Core/get_next_line/)
Function to read a file line by line from a file descriptor (file, stdin, socket, etc.).

**Skills** : Buffer management, dynamic allocation, I/O.

### [minitalk](Common_Core/minitalk/)
Client/server program using **Unix signals** (`SIGUSR1`, `SIGUSR2`) to transmit messages between processes.

**Skills** : Inter-process communication, signals, binary encoding.

### [so_long](Common_Core/so_long/)
2D maze-style game built with **MiniLibX**. Collect all items before reaching the exit.

**Skills** : Graphics programming, pathfinding algorithms, event handling.

### [push_swap](Common_Core/push_swap/)
Sort a stack of integers using a limited set of operations (swap, push, rotate). Optimize the number of moves.

**Skills** : Sorting algorithms, data structures (stacks).

### [cub3d](Common_Core/cub3d/)
3D **raycasting** game (Wolfenstein 3D-style). Real-time rendering with MiniLibX, `.cub` map parsing.

**Skills** : Mathematics (raycasting), graphics programming, parsing.

### [minishell](Common_Core/minishell/)
Unix shell reimplementation (bash-like): pipes, redirections, environment variables, builtins.

**Skills** : Systems programming, processes, pipes, command parsing.

### [ft_irc](Common_Core/ft_irc/)
**IRC** server in C++: channel management, users, IRC commands (JOIN, PRIVMSG, etc.).

**Skills** : C++, sockets, network protocols, client/server architecture.

### [inception](Common_Core/inception/)
Complete **Docker** stack: WordPress, MariaDB, Nginx, containerized with Docker Compose.

**Skills** : Docker, Docker Compose, virtualization, web services.

### [netpractice](Common_Core/netpractice/)
Network configuration exercises: subnets, masks, routing, IP addresses.

**Skills** : Networking, TCP/IP, addressing.

### [born2beroot](Common_Core/born2beroot/)
**Debian VM** setup according to strict specifications: SSH, sudo, firewall (UFW), password policy, monitoring.

**Skills** : Linux system administration, security, virtualization.

### [cpp00 → cpp09](Common_Core/)
**C++** modules from the 42 curriculum:
- **cpp00** : Namespace, classes, streams
- **cpp01** : Memory, new/delete
- **cpp02** : Fixed-point types, operator overloading
- **cpp03** : Inheritance, classes
- **cpp04** : Polymorphism, abstract classes
- **cpp05** : Exceptions
- **cpp06** : C++ casts
- **cpp07** : Templates
- **cpp08** : Containers, STL algorithms
- **cpp09** : Advanced STL

**Skills** : C++, OOP, templates, STL.

### [Piscine_Reloaded](Common_Core/Piscine_Reloaded/)
C revision exercises post-Piscine (strings, pointers, etc.).

---

## 🏊 Piscine Projects

### [BSQ](42Piscine/BSQ/)
**Biggest Square** — Algorithm finding the largest empty square in a map with obstacles.

**Skills** : Algorithms, dynamic programming, parsing.

### [Days](42Piscine/Days/)
C exercises from the Piscine (c00 to c10): basic functions, pointers, allocation, files.

**Skills** : C fundamentals.

### [Rush](42Piscine/Rush/)
2-day group projects: rush00 (display), rush01 (Sudoku).

**Skills** : Teamwork, C.

### [Shell](42Piscine/Shell/)
Shell scripts (bash): file manipulation, variables, loops.

**Skills** : Scripting, Linux.

---

## 🚀 Installation & Usage

Each project is standalone with its own `Makefile`. Example:

```bash
# Build
cd Common_Core/libft && make

# Clean
make fclean

# Rebuild
make re
```

See each subproject's `README.md` for detailed instructions.

---

## 💡 Skills Demonstrated

| Domain | Projects |
|--------|----------|
| **C** | libft, ft_printf, get_next_line, BSQ, so_long, cub3d, minishell, push_swap |
| **C++** | cpp00-09, ft_irc |
| **Data structures** | libft, push_swap |
| **Systems (Unix)** | minitalk, minishell |
| **Networking** | ft_irc, minitalk, netpractice |
| **Graphics** | so_long, cub3d (MiniLibX) |
| **Algorithms** | BSQ, so_long, push_swap, cub3d (raycasting) |
| **DevOps / Docker** | inception |
| **System admin** | born2beroot |
| **Scripting** | Shell (Piscine) |
| **OOP / Templates** | cpp02-09 |

---

## 📄 License

This project is licensed under the [MIT License](LICENSE). See the LICENSE file for details.

---

*If this portfolio was helpful, feel free to leave a ⭐!*
