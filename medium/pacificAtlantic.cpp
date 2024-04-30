#include <vector>
using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(n, vector<bool>(m));
        vector<vector<bool>> atlantic(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            detectFlow(heights, pacific, i, 0);
            detectFlow(heights, atlantic, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            detectFlow(heights, pacific, 0, i);
            detectFlow(heights, atlantic, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atlantic[i][j] && pacific[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
private:
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void detectFlow(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int row, int col) {
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int new_row = row + directions[i][0];
            int new_col = col + directions[i][1];
            if (new_row < 0 || new_row >= heights.size() || new_col < 0 || new_col >= heights[0].size()) 
                continue;
            if (!ocean[new_row][new_col] && heights[new_row][new_col] >= heights[row][col])
                detectFlow(heights, ocean, new_row, new_col); 
        }
    }
};