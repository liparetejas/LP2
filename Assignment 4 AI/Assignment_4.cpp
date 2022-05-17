/*
Name: Tejas Lipare
Roll: 31149
Assignment: 4 (AI/LP-II)
Problem Statement: Implement a solution for a Constraint Satisfaction Problem using
Branch and Bound and Backtracking for n-queens problem or a graph coloring problem.
*/



















#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

// Size of the board
int N;


// This function prints the board.
void printBoard(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
















// This function checks for the safe position.
bool isSafeBacktracking(vector<vector<int>> board, int r, int c)
{
    // Check for attacking queen in the same row to the left side
    for (int i = 0; i < c; i++)
    {
        if (board[r][i] == 1)
            return false;
    }

    // Check for attacking queen on the upper diagonal to the left side
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check for attacking queen on the upper diagonal to the left side
    for (int i = r, j = c; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Return true if it's a safe position
    return true;
}

// This function solves NQueens problem using recursion and backtracking.
bool solveNQueenBacktracking(vector<vector<int>> &board, int c)
{
    // Return true if all columns have been processed
    if (c >= N)
        return true;

    // Start placing queens on each rows
    for (int i = 0; i < N; i++)
    {
        // Check for safe position
        if (isSafeBacktracking(board, i, c))
        {
            // Mark position as part of solution if it is safe
            board[i][c] = 1;

            // Go for next queen on next column
            if (solveNQueenBacktracking(board, c + 1))
                return true;

            // Backtrack and unmark the position as not a part of solution
            board[i][c] = 0;
        }
    }

    // Return false if solution does not exist
    return false;
}

// This function checks for the safe position.
bool isSafeBranchBound(int r, int c,
                       vector<vector<int>> &primDiagonal,
                       vector<vector<int>> &secDiagonal,
                       vector<bool> &rowLookup,
                       vector<bool> &primDiagonalLookup,
                       vector<bool> &secDiagonalLookup)
{
    if (primDiagonalLookup[primDiagonal[r][c]] ||
        secDiagonalLookup[secDiagonal[r][c]] ||
        rowLookup[r])
        return false;
    return true;
}

// This function solves NQueens problem using branch and bound.
bool solveNQueensBranchBound(vector<vector<int>> &board,
                             int c,
                             vector<vector<int>> &primDiagonal,
                             vector<vector<int>> &secDiagonal,
                             vector<bool> &rowLookup,
                             vector<bool> &primDiagonalLookup,
                             vector<bool> &secDiagonalLookup)
{
    // Return true if all columns have been processed
    if (c >= N)
        return true;

    // Start placing queens on each rows
    for (int i = 0; i < N; i++)
    {
        // Check for safe position
        if (isSafeBranchBound(i, c, primDiagonal, secDiagonal,
                              rowLookup, primDiagonalLookup, secDiagonalLookup))
        {
            // Mark position as part of solution if it is safe
            board[i][c] = 1;
            rowLookup[i] = true;
            primDiagonalLookup[primDiagonal[i][c]] = true;
            secDiagonalLookup[secDiagonal[i][c]] = true;

            // Go for next queen on next column
            if (solveNQueensBranchBound(board, c + 1, primDiagonal, secDiagonal,
                                        rowLookup, primDiagonalLookup, secDiagonalLookup))
                return true;

            // Backtrack and unmark the position as not a part of solution
            board[i][c] = 0;
            rowLookup[i] = false;
            primDiagonalLookup[primDiagonal[i][c]] = false;
            secDiagonalLookup[secDiagonal[i][c]] = false;
        }
    }

    // Return false if solution does not exist
    return false;
}

// Solve problem using backtracking appraoch
void solveUsingBacktracking()
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQueenBacktracking(board, 0))
    {
        printBoard(board);
    }
    else
    {
        cout << "Solution does not exist!" << endl;
    }
}

// Solve problem using branch and bound
void solveUsingBranchBound()
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Helping matrices
    vector<vector<int>> primDiagonal(N, vector<int>(N, 0));
    vector<vector<int>> secDiagonal(N, vector<int>(N, 0));

    // Arrays to tell us which rows are occupied
    vector<bool> rowLookup(N, false);

    // Keep two arrays to tell us which diagonals are occupied
    vector<bool> primDiagonalLookup(2 * N - 1, false);
    vector<bool> secDiagonalLookup(2 * N - 1, false);

    // Initialize helper matrices
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
        {
            primDiagonal[r][c] = r + c;
            secDiagonal[r][c] = r - c + 7;
        }

    if (solveNQueensBranchBound(board, 0, primDiagonal, secDiagonal, rowLookup,
                                primDiagonalLookup, secDiagonalLookup))
    {
        printBoard(board);
    }
    else
    {
        cout << "Solution does not exist!" << endl;
    }
}

int main()
{
    cout << "Enter size of board (N): ";
    cin >> N;
    cout << "Solution using backtracking: \n";
    solveUsingBacktracking();
    cout << "\nSolution using branch and bound: \n";
    solveUsingBranchBound();
    return 0;
}

/*
Output:
Enter size of board (N): 8
Solution using backtracking:
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0

Solution using branch and bound:
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
*/