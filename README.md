# Tic-Tac-Toe in C

## Overview
This is a simple command-line Tic-Tac-Toe game implemented in C. The game allows a human player to play against the computer. The player marks "X" on the board, while the computer marks "O".

## Features
- Simple text-based UI using the terminal.
- Turn-based gameplay.
- The computer makes strategic moves using a basic AI algorithm.
- The game detects wins, losses, and draws.

## How to Play
1. The game starts with an empty 3x3 grid.
2. The player is prompted to enter row and column numbers (1-3) to place an 'X'.
3. The computer responds with its move.
4. The game checks for a win, loss, or draw after each move.
5. The game ends when either the player or computer wins or the grid is full.

## Compilation & Execution
To compile the code, use:
```sh
gcc tic_tac_toe.c -o tic_tac_toe
```
To run the game, use:
```sh
./tic_tac_toe
```

## Code Structure
- `clearScreen()`: Clears the console screen.
- `printGrid()`: Prints the game board.
- `playerMove()`: Handles player's move.
- `isGameOver()`: Checks if the board is full (draw condition).
- `checkWinner()`: Checks if a player has won.
- `computerMove()`: Implements the computer's move logic.

## Future Enhancements
- Implement a minimax algorithm for smarter AI.
- Add support for multiplayer mode.
- Improve user interface with a GUI.

## License
This project is open-source and can be modified freely.

