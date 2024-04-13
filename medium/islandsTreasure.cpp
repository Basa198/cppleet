#include <vector>
#include <queue>

int INF = 2147483647;

class Solution {
public:
    void islandsAndTreasure(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }        

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int temp_x = x + directions[i][0];
                int temp_y = y + directions[i][1];
                if (temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= m || grid[temp_x][temp_y] != INF) 
                    continue;
                
                grid[temp_x][temp_y] = 1 + grid[x][y];
                q.push({temp_x, temp_y});
            }
        }
    }
private: 
    std::vector<std::vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main() {
    std::vector<std::vector<int>> grid {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}
    };

    Solution sol;
    sol.islandsAndTreasure(grid);
}
