#define N 8
#include <stdbool.h>
#include <stdio.h>
void printSolution(int board[N][N])
{
	int i,j;
	for (i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			if(board[i][j])
				printf("Q ");
			else
				printf("x ");
		}
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Check lower diagonal on left side
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}
bool solveNQUtil(int board[N][N], int col)
{
	int i;
	// Base case: If all queens are placed
	// then return true
	if (col >= N)
		return true;

	// Consider this column and try placing
	// this queen in all rows one by one
	for (i = 0; i < N; i++) {
		
		// Check if the queen can be placed on
		// board[i][col]
		if (isSafe(board, i, col)) {
			
			// Place this queen in board[i][col]
			board[i][col] = 1;

			// Recur to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;

			// If placing queen in board[i][col]
			// doesn't lead to a solution, then
			// remove queen from board[i][col]
			board[i][col] = 0; // BACKTRACK
		}
	}
	return false;
}
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0},
						{ 0, 0, 0, 0 , 0, 0, 0, 0} };

	if (solveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}



