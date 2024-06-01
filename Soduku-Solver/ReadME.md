# Sudoku Solver

This repository contains a C++ program that solves Sudoku puzzles using backtracking algorithm.

## How to Use

1. Clone the repository to your local machine.
2. Compile the `Main.cpp` file using a C++ compiler.
3. Execute the compiled binary to solve Sudoku puzzles.

## Usage Example

```bash
$ g++ Main.cpp -o sudoku_solver
$ ./sudoku_solver
```

## Sudoku Grid Input

The Sudoku grid is represented as a 9x9 2D array where each cell contains either a number from 1 to 9 or 0 for empty cells. The provided example grid is:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## Output

The program will print the solved Sudoku grid if a solution exists, otherwise, it will print "No solution exists".
