#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<char> rows[9];
        for (int i = 0; i < 9; i++) {
          std::unordered_set<char> row;
          std::unordered_set<char> col;
          for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
              if (row.find(board[i][j]) != row.end()) return false;
              row.insert(board[i][j]);
            }
            if (board[j][i] != '.') {
              if (col.find(board[j][i]) != col.end()) return false;
              col.insert(board[j][i]);
            }
            if (i % 3 == 0 && j % 3 == 0) {
              if (!check_square(board, i, j)) return false;
            }
          }
        }
        return true;
    }

private:
  bool check_square(std::vector<std::vector<char>>& board, int row, int col) {
    std::unordered_set<char> sq;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[row + i][col + j] != '.') {
          if (sq.find(board[row + i][col + j]) != sq.end()) return false;
          sq.insert(board[row + i][col + j]);
        }
      }
    }
    return true;
  }
};