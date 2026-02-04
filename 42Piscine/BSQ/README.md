# BSQ — Biggest Square

Algorithm finding the **largest empty square** in a map containing obstacles. 42 Piscine algorithm project.

## Description

BSQ analyzes a map (character grid) and determines the largest square of empty cells while avoiding obstacles. The solution uses **dynamic programming** for optimal complexity.

### Map Format

- First line: number of rows, characters for empty/obstacle/filled
- Following lines: the grid

Example:
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

## Build

> **Note**: If the file is named `Makefile.txt`, rename it to `Makefile` to use `make`.

```bash
make        # Build bsq executable
make clean
make fclean
make re
```

## Usage

### With a file

```bash
./bsq map.txt
```

### With multiple files

```bash
./bsq map1.txt map2.txt map3.txt
```

### Standard input

```bash
echo "4.ox
....
....
....
...." | ./bsq
```

### Map generator (Perl)

```bash
perl gen.sh <width> <height> <density> > map.txt
./bsq map.txt
```

**Example:** `perl gen.sh 20 20 5 > test.ber` generates a 20×20 map with ~5% obstacles.

## Constraints

- Maximum map size: **1023 × 1023**

## Architecture

- `bsq.c` — Entry point
- `map.c` / `map_utils.c` — Map reading and parsing
- `read.c` — Input handling
- `solve.c` / `solve_utils.c` — Biggest square algorithm

## Skills

- Dynamic programming
- File parsing
- Grid algorithms
