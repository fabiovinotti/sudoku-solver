#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

// Solves the board starting with the cell at the given coordinates.
// Returns 1 when the board is solved, 0 when it can't be solved.
int solve(int (*board)[9], int row, int col);

#endif