#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> ans;
        std::vector<std::vector<int>> directions { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; 
        std::vector<std::vector<bool>> traversed (rows, std::vector<bool>(cols));
        int row = 0;
        int col = 0;
        int cycle = 0;
        while (ans.size() != rows * cols) {
            while (row >= 0 && col >= 0 && row < rows && col < cols && !traversed[row][col]) {
                ans.push_back(matrix[row][col]);
                traversed[row][col] = true;
                row += directions[cycle][0];
                col += directions[cycle][1];
            }
            row -= directions[cycle][0];
            col -= directions[cycle][1];
            cycle = (cycle + 1) % 4;
            row += directions[cycle][0];
            col += directions[cycle][1];
        }

        return ans;
    }
};