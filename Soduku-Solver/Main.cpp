#include <iostream>
using namespace std;

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Function to check if a given number is safe to be placed in a specific position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // TO Check if the number is not already present in the row or column
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    // Check if the number is not already present in the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Function to solve the Sudoku grid recursively using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    // If there is no unassigned location, we are done
    bool found = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found) return true; // If there is no unassigned location, we are done

    // Try numbers 1 to 9 in the current unassigned location
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Assign the number to the current location
            if (solveSudoku(grid)) return true; // Recursively solve for the rest of the grid
            grid[row][col] = 0; // If no number is valid, reset the current location and backtrack
        }
    }
    return false; // If no number is valid, backtrack
}

int main() {
    int grid[N][N] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9} };

    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
