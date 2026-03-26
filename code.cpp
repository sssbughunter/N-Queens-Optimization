#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int N;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check queen at (row, col) is safe
bool isSafe(const vector<int>& queens, int row, int col) {
    for (int r = 0; r < row; ++r) {
        int c = queens[r];
        if (c == col || abs(row - r) == abs(col - c)) return false;
    }
    return true;
}

long long solutionCount = 0;

// Recursive hybrid solver (row-wise)
void hybridQueens(int row, vector<int>& queens, int prev_row, int prev_col) {
    if (row == N) {
        solutionCount++;
        return;
    }
    // 1. Try all knight-move columns from prev queen
    bool tried_knight = false;
    for (int d = 0; d < 8; ++d) {
        int krow = prev_row + dx[d];
        int kcol = prev_col + dy[d];
        if (krow == row && kcol >= 0 && kcol < N && isSafe(queens, row, kcol)) {
            tried_knight = true;
            queens[row] = kcol;
            hybridQueens(row + 1, queens, row, kcol);
            queens[row] = -1;
        }
    }
    // 2. If knight-move fails, try all columns as chain-break
    if (!tried_knight) {
        for (int col = 0; col < N; ++col) {
            if (isSafe(queens, row, col)) {
                queens[row] = col;
                hybridQueens(row + 1, queens, row, col);
                queens[row] = -1;
            }
        }
    }
}

int main() {
    cout << "Enter board size n: ";
    cin >> N;
    vector<int> queens(N, -1);
    auto start = chrono::high_resolution_clock::now();
    // Try every column in first row as starting point
    for (int start_col = 0; start_col < N; ++start_col) {
        queens[0] = start_col;
        hybridQueens(1, queens, 0, start_col);
        queens[0] = -1;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Total solutions found: " << solutionCount << endl;
    cout << "Time taken: " << elapsed.count() << " ms" << endl;
    return 0;
}
