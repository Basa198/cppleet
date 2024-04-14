#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') sweepAndMark(board, 0, i, n, m);
            if (board[n - 1][i] == 'O') sweepAndMark(board, n - 1, i, n, m);
        }
        for (int i = 1; i < n; i++) {
            if (board[i][0] == 'O') sweepAndMark(board, i, 0, n, m);
            if (board[i][m - 1] == 'O') sweepAndMark(board, i, m - 1, n, m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
private:
    std::vector<std::vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void sweepAndMark(std::vector<std::vector<char>>& board, int i, int j, int n, int m) {
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int row = i + directions[k][0];
            int col = j + directions[k][1];

            if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 'O')
                continue;
            
            sweepAndMark(board, row, col, n, m);
        }
    }
};

int main() {
    std::vector<std::vector<char>> a {{'O', 'O', 'O'}, {'O', 'O', 'O'},{'O', 'O', 'O'}};

    Solution sol;
    sol.solve(a);
}