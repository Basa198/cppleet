#include <vector>
#include <string>

std::vector<std::vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int row_num = board.size();
        int col_num = board[0].size();
        std::vector<std::vector<bool>> used(row_num, std::vector<bool>(col_num));
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (word[0] == board[i][j]) {
                    used[i][j] = true;
                    if (exist(board, word, used, i, j, 1)) return true;
                    used[i][j] = false;
                }
            }   
        }
        return false;
    }
private:
    bool exist(std::vector<std::vector<char>>& board, std::string word, std::vector<std::vector<bool>>& used, int row, int col, int letter_index) {
        if (letter_index >= word.size()) return true;
        for (int i = 0; i < 4; i++) {
            int temp_row = row + directions[i][0];
            int temp_col = col + directions[i][1];
            if (temp_row >= 0 && temp_row < board.size() && temp_col >= 0 && temp_col < board[0].size() 
                && !used[temp_row][temp_col] && board[temp_row][temp_col] == word[letter_index]) {
                    used[temp_row][temp_col] = true;
                    if (exist(board, word, used, temp_row, temp_col, letter_index + 1)) return true;
                    used[temp_row][temp_col] = false;
            }
        }
        return false;
    }
};