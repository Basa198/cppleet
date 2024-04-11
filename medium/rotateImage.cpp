#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size() - 1;

        for (int row = 0; row < (n + 2) / 2; row++) {
            for (int col = 0; col < (n + 1) / 2; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[n - col][row];
                matrix[n - col][row] = matrix[n - row][n - col]; 
                matrix[n - row][n - col] = matrix[col][n - row];
                matrix[col][n - row] = temp;
            }
        }
    }
};