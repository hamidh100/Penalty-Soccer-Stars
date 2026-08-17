# Penalty Soccer Stars

A 2D turn-based penalty shootout game developed with **C++** and **SDL2**.

Players take turns shooting and defending penalties, with multiple teams available to choose from.

## Features

- Turn-based penalty shootout gameplay
- Player and goalkeeper mechanics
- Multiple team selections
- Score tracking
- Sound effects and game audio
- Interactive menus and team information

## Technologies

- C++
- SDL2
- SDL2_image
- SDL2_mixer

## Project History

This project was created in **2021** as a team project.

### Team Members

- Sourena
- Amirvala
- Me

## Running on Linux

### Dependencies

On Ubuntu/Debian-based systems:

```bash
sudo apt update
sudo apt install build-essential libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev
```

### Compile

From the project root:

```bash
g++ main.cpp -o game.out $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_mixer
```

### Run

```bash
./game.out
```

Make sure to run the game from the project root so that the paths to the files in `assets/` are resolved correctly.

## Windows

`main_windows.cpp` contains the Windows version of the project.

## License

This project was created as a team project for educational purposes.
