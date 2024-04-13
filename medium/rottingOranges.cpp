#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count_of_fresh = 0;
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) count_of_fresh += 1;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                } 
            }
        }
        q.push({-1, -1});
        int minutes = -1;
        if (count_of_fresh == 0) return minutes;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == -1) {
                minutes++;
                if (!q.empty()) {
                    q.push({-1, -1});
                } 
            } else {
                for (int i = 0; i < 4; i++) {
                    int t_x = x + directions[i][0];
                    int t_y = y + directions[i][1];

                    if (t_x < 0 || t_x >= n || t_y < 0 || t_y >= m || grid[t_x][t_y] != 1) continue;
                    grid[t_x][t_y] = 2;
                    count_of_fresh -= 1;
                    q.push({t_x, t_y});
                }
            }
        }
        return count_of_fresh == 0 ? minutes : -1;
    }
private:
    std::vector<std::vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};