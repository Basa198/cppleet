#include <vector>
#include <iostream>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int l = 0;
        int r = matrix.size() * cols;

        while (l <= r) {
            int m = (r + l) / 2;
            int row = m / cols;
            int col = m % cols;

            if (row >= matrix.size() || col >= cols) return false;

            if (target > matrix[row][col]) {
                l = m + 1;
            } else if (target < matrix[row][col]) {
                r = m - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};


int main() {
    Solution sol;

    std::vector<std::vector<int>> a1 {{1}};

    sol.searchMatrix(a1, 2);
}   