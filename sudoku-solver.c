#include "sudoku-solver.h"

int isInRow(int n, int row, int (*board)[9]);
int isInCol(int n, int col, int (*board)[9]);
int isInGrid(int n, int row, int col, int (*board)[9]);
int isValidPlacement(int n, int row, int col, int (*board)[9]);

int solve(int (*board)[9], int row, int col) {
  int val;

  if (col > 8) {
    if (row + 1 > 8)
      return 1;
    col = 0;
    row++;
  }

  if (board[row][col] != 0) {
    if (solve(board, row, col + 1))
      return 1;
  }
  else {
    for (val = 1; val <= 9; val++)
      if (isValidPlacement(val, row, col, board)) {
        board[row][col] = val;
        if (solve(board, row, col + 1))
          return 1;
      }

    board[row][col] = 0;
  }

  return 0;
}

int isValidPlacement(int n, int row, int col, int (*board)[9]) {
  if (
    isInRow(n, row, board) ||
    isInCol(n, col, board) ||
    isInGrid(n, row, col, board)
  ) return 0;
  return 1;
}

int isInRow(int n, int row, int (*board)[9]) {
  int col = 0;

  board += row;
  while (col < 9)
    if ((*board)[col++] == n)
      return 1;
  return 0;
}

int isInCol(int n, int col, int (*board)[9]) {
  int row;
  for (row = 0; row < 9; row++)
    if (board[row][col] == n)
      return 1;
  return 0;
}

int isInGrid(int n, int row, int col, int (*board)[9]) {
  row = row / 3 * 3;
  col = col / 3 * 3;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[row + i][col + j] == n)
        return 1;

  return 0;
}