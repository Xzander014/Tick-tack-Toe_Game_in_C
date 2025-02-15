#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define GRID_SIZE 3 // Size of the Tic-Tac-Toe grid

// Function prototypes
void clearScreen();
void printGrid(int grid[GRID_SIZE][GRID_SIZE]);
void playerMove(int grid[GRID_SIZE][GRID_SIZE], int row, int col);
bool isGameOver(int grid[GRID_SIZE][GRID_SIZE]);
bool checkWinner(int grid[GRID_SIZE][GRID_SIZE]);
void computerMove(int grid[GRID_SIZE][GRID_SIZE]);

int main()
{
    int grid[GRID_SIZE][GRID_SIZE] = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2},
    };

    int row, col;
    printf("Tic-Tac-Toe Game Start:\n");
    while (true)
    {
        clearScreen();
        printGrid(grid);

        // Player's move
        printf("\nEnter row and column (1-3): ");
        scanf("%d,%d", &row, &col);
        row--;
        col--;
        
        // Check for valid move
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE || grid[row][col] != 2)
        {
            printf("Invalid move. Try again.\n");
            sleep(1);
            continue;
        }

        playerMove(grid, row, col);

        if (checkWinner(grid))
        {
            clearScreen();
            printGrid(grid);
            printf("You win!\n");
            break;
        }
        
        if (isGameOver(grid))
        {
            clearScreen();
            printGrid(grid);
            printf("It's a draw!\n");
            break;
        }

        // Computer's move
        computerMove(grid);

        if (checkWinner(grid))
        {
            clearScreen();
            printGrid(grid);
            printf("Computer wins!\n");
            break;
        }
        
        if (isGameOver(grid))
        {
            clearScreen();
            printGrid(grid);
            printf("It's a draw!\n");
            break;
        }
    }
    printf("Game Over\n");
    return 0;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Prints the Tic-Tac-Toe grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        printf("----+---+----\n");
        for (int j = 0; j < GRID_SIZE; j++)
        {
            char symbol = ' ';
            if (grid[i][j] == 0)
                symbol = 'X'; // Player
            else if (grid[i][j] == 1)
                symbol = 'O'; // Computer
            printf("| %c ", symbol);
        }
        printf("|\n");
    }
    printf("----+---+----\n");
}

// Sets player's move
void playerMove(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
    grid[row][col] = 0;
}

// Checks if the grid is full (draw condition)
bool isGameOver(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (grid[i][j] == 2)
                return false;
    return true;
}

// Checks if there is a winner
bool checkWinner(int grid[GRID_SIZE][GRID_SIZE])
{
    // Check diagonals
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != 2) ||
        (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 2))
        return true;
    
    // Check rows and columns
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != 2) ||
            (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != 2))
            return true;
    }
    return false;
}

// Determines the computer's move
void computerMove(int grid[GRID_SIZE][GRID_SIZE])
{
    // Try to win
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (grid[i][j] == 2)
            {
                grid[i][j] = 1;
                if (checkWinner(grid))
                    return;
                grid[i][j] = 2;
            }

    // Block player
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (grid[i][j] == 2)
            {
                grid[i][j] = 0;
                if (checkWinner(grid))
                {
                    grid[i][j] = 1;
                    return;
                }
                grid[i][j] = 2;
            }
    
    // Take center or corners
    if (grid[1][1] == 2)
    {
        grid[1][1] = 1;
        return;
    }
    int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int k = 0; k < 4; k++)
    {
        int i = corners[k][0], j = corners[k][1];
        if (grid[i][j] == 2)
        {
            grid[i][j] = 1;
            return;
        }
    }

    // Take any available cell
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (grid[i][j] == 2)
            {
                grid[i][j] = 1;
                return;
            }
}
