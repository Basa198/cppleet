#include <vector>
#include <algorithm>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int max = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 1) {
                    max = std::max(max, areaOfIsland(grid, i, j, rows, cols));
                }
            }
        }
        return max;
    }
private:
    std::vector<std::vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int areaOfIsland(std::vector<std::vector<int>>& grid, int row, int col, int n, int m) {
        grid[row][col] = 0;
        int count = 1;
        for (int i = 0; i < 4; i++) {
            int temp_row = row + directions[i][0];
            int temp_col = col + directions[i][1];
            if (temp_row >= 0 && temp_row < n && temp_col >= 0 && temp_col < m
                && grid[temp_row][temp_col] == 1) {
                //
                count += areaOfIsland(grid, temp_row, temp_col, n, m);
            }
        }
        return count;
    }
};