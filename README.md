*This project has been created as part of the 42 curriculum by ssutarmi.*

# FDF — Wireframe Model

## Description

FDF (fil de fer) is a 3D wireframe renderer that reads a heightmap from a `.fdf` file and displays it as an isometric projection in a graphical window. Each point in the input file represents a coordinate in space where the horizontal position gives the X axis, the vertical position gives the Y axis, and the value itself represents the altitude (Z axis). The program connects these points with line segments to produce a landscape visualization.

The rendering relies on the **MiniLibX** graphical library for window management and pixel-level drawing, and uses the **Bresenham line algorithm** to trace edges between neighboring points efficiently. An isometric projection (based on a π/6 angle) transforms the 3D grid into a 2D image.

The bonus part adds interactive features: translation via arrow keys, zoom via scroll wheel, and rotation via the `E` key.

## Instructions

### Prerequisites

- A Linux environment with X11 support
- `cc` compiler
- `make`
- The MiniLibX library (add minlibx file from subject, extract sub-file and rename in `mlx_linux/`)
- The Libft library (included under `Libft/`)

### Compilation

```
make        # Builds the mandatory part
make bonus  # Builds with bonus features (translation, zoom, rotation)
make clean  # Removes object files
make fclean # Removes object files and the executable
make re     # Full recompile
```

### Execution

```
./fdf path/to/map.fdf
```

Example:
```
./fdf maps/42.fdf
```

### Controls

| Key / Action        | Effect                     |
|---------------------|----------------------------|
| `ESC`               | Close the window and exit  |
| Click window cross  | Close the window and exit  |
| Arrow keys (bonus)  | Translate the model        |
| Scroll up (bonus)   | Zoom in                    |
| Scroll down (bonus) | Zoom out                   |
| `E` (bonus)         | Rotate the model           |

## Architecture

The project is organized into the following modules:

- **Parsing** — Reads the `.fdf` file line by line using `get_next_line` and `ft_split`, building a linked list of rows where each cell stores an altitude and an optional color.
- **Mapping** — Converts the parsed data into a numeric grid with computed gaps, unit vectors for the isometric projection, and Z-axis scaling.
- **Drawing** — Iterates over the grid and draws line segments between adjacent points using Bresenham's algorithm, handling both predominantly horizontal and predominantly vertical lines.
- **Transformations (bonus)** — Handles real-time translation, zoom (scaling unit vectors), and rotation (updating the reference angle and recomputing trigonometric values).
- **Window management** — Sets up MiniLibX hooks for keyboard and mouse events, displays the rendered image, and ensures clean shutdown.
- **Cleaning** — Frees all allocated memory (map linked list, coordinate grid, MiniLibX resources) before exit.

## Resources

- [MiniLibX documentation — 42Docs](https://harm-smits.github.io/42docs/libs/minilibx)
- [Bresenham's line algorithm — Wikipedia](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
- [Isometric projection — Wikipedia](https://en.wikipedia.org/wiki/Isometric_projection)
- [42 FDF subject (v5.0)](en_subject.pdf)

### AI Usage

AI (Claude by Anthropic) was used during the project for the following tasks:

- Understanding the mathematical foundations of isometric projection and how to decompose 3D-to-2D coordinate transformations using unit vectors.
- Clarifying the Bresenham line drawing algorithm and its two-case variant (horizontal-dominant vs vertical-dominant).
- Debugging memory management patterns (linked list traversal and freeing nested allocations).
- Generating this README file.

No AI-generated code was directly copied into the project. All code was written, tested, and understood by the author.
