
![Screenshot from 2025-03-19 16-22-35](https://github.com/user-attachments/assets/aa59c7f4-68ee-48b7-ab6f-cbca27cdfe87)


# cub3D  
## Grade: 115/100
![cub3d](https://github.com/user-attachments/assets/13880b9d-e51f-47dd-b9f5-de3e58760552)

## Overview

cub3D is a raycasting engine project written in C that simulates a 3D environment from a 2D map—reminiscent of classic first-person shooters. In this project, I implemented the core engine along with several bonus features including a real-time minimap, robust wall collision detection, and smooth mouse-controlled camera movement.

## Features

- **Raycasting Engine:** Renders a 3D view using raycasting techniques based on a 2D map.
- **Minimap Bonus:** Displays an overhead view of the map that updates dynamically as the player moves.
- **Wall Collision Detection Bonus:** Prevents the player from moving through walls, ensuring realistic navigation.
- **Mouse Movement Bonus:** Allows smooth, intuitive player rotation using mouse input.
- **42 Norm Compliance:** All code adheres strictly to the 42 coding standards.

## Project Details

- **Language:** C  
- **Dependencies:**  
  - MiniLibX (MLX) for graphics rendering  
  - Standard C libraries (math, system calls, etc.)
- **Compilation:**  
  The project is compiled with the flags: `-Wall -Wextra -Werror`
- **Testing:**  
  Extensively tested to ensure reliable rendering, responsive controls, and accurate collision detection.

## Usage

***To compile cub3D:***
```bash
make
```

***To run the project:***
./cub3D
