#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count += 1;
                    mark_island(grid, i, j);
                }
            }
        }
        return count;
    }
private:
    std::vector<std::vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void mark_island(std::vector<std::vector<char>>& grid, int row, int col) {
        grid[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            int temp_row = row + directions[i][0];
            int temp_col = col + directions[i][1];
            if (temp_row >= 0 && temp_row < grid.size() && temp_col >=0 && temp_col < grid[0].size() 
                && grid[temp_row][temp_col] == '1') 
                mark_island(grid, temp_row, temp_col);
        }
    }
};