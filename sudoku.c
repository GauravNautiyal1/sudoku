//Program to solve sudoku 
#include<stdio.h>
#define N 9

int grid[N][N];
void inputGrid() {
    // Code to input the Sudoku puzzle
               printf("Enter the Sudoku puzzle (use '0' for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

}

void displayGrid() {
    // Code to display the Sudoku grid
      printf("Sudoku Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
int isValid(int row, int col, int num) {
    // Check if the number is already present in the row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check if the number is already present in the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}
int solveSudoku() {
    int row, col;

    // Find an empty cell
    int isFilled = 1;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isFilled = 0;
                break;
            }
        }
        if (!isFilled) {
            break;
        }
    }

    // If all cells are filled, the puzzle is solved
    if (isFilled) {
        return 1;
    }

    // Try placing numbers in the empty cell
    for (int num = 1; num <= N; num++) {
        if (isValid(row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku()) {
                return 1;
            }
            // Backtrack
            grid[row][col] = 0;
        }
    }

    // No solution found
    return 0;
}
int main() {
    inputGrid();
    
    if (solveSudoku()) {
        displayGrid();
    } else {
        printf("No solution exists.");
    }

    return 0;
}
