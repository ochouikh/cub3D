# Cub3D - 3D game in C

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It is a project from the 42 school curriculum. The goal is to create a dynamic view inside a maze, in which you can walk around. The game is coded in C, using the raycasting technique.

## Table of Contents
- [Requirements](#Requirements)
- [Installation](#Installation)
- [Usage](#Usage)
- [Features](#Features)
- [Contributors](#Contributors)

## Requirements
- gcc
- make
- X11
- Minilibx

## Installation
1. Clone the repository
```sh
git clone git@github.com:ochouikh/cub3D.git
cd cub3D
```
2. Compile the project
```sh
make
```
3. Run the game
```sh
./cub3D maps/map.cub
```

## Usage

- Move forward: W
- Move backward: S
- Move left: A
- Move right: D
- Rotate left: Left arrow
- Rotate right: Right arrow
- Rotate up: Up arrow
- Rotate down: Down arrow
- Exit the game: ESC

## Features
- [x] Display a 3D maze using raycasting
- [x] Move in the maze using the keyboard
- [x] Rotate the view using the mouse
- [x] Textures
- [x] Animated Sprites (enemies)
- [x] Floor and ceiling textures
- [x] Doors that can be opened and closed
- [x] Minimap with player position

## Contributors
* [Houssam eddine](https://github.com/hel-mamo)