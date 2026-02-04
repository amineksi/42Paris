# so_long

2D maze-style game built with **MiniLibX**. Collect all items before reaching the exit. 42 Common Core project.

## Description

`so_long` is a graphical C game that implements:

- **Graphics rendering** via MiniLibX (window, sprites, events)
- **Map parsing** in `.ber` format (text)
- **Pathfinding** — verifies a valid path exists (collectibles + exit reachable)
- **Key handling** (WASD or arrows) and clean shutdown

### Map Elements

| Character | Role |
|-----------|------|
| `1` | Wall |
| `0` | Floor |
| `P` | Player (starting position) |
| `C` | Collectible |
| `E` | Exit |

## Prerequisites

- **MiniLibX** (Linux): `libmlx_linux.a` and headers in `include/`
- **X11**: `libXext`, `libX11`
- **libft**: included in the project

## Build

```bash
make        # Build so_long executable
make clean
make fclean
make re
```

## Usage

```bash
./so_long maps/valid.ber
```

### Map Format (.ber)

- Rectangular, surrounded by walls
- One `P`, one `E`, at least one `C`
- Minimal example:

```
111111
1P0C01
1C00E1
111111
```

## Project Structure

```
so_long/
├── src/           # Source code
│   ├── main.c
│   ├── creating_map.c   # Reading and parsing
│   ├── drawing_map.c    # Graphics rendering
│   ├── handle_keys.c    # Input handling
│   ├── algo_path.c      # Path verification
│   └── ...
├── maps/          # Test maps
├── assets/        # XPM sprites
├── libft/         # Custom library
└── include/       # Headers (mlx, libft)
```

## Skills

- Graphics programming (MiniLibX)
- Pathfinding algorithms (BFS/DFS)
- Memory management and clean deallocation
- Parsing and data validation
