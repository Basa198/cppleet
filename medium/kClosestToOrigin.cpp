#include <vector>
#include <queue>
#include <cmath>

struct PairComparator {
    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) const {
        return p1.first > p2.first; // Prioritize smaller first elements
    }
};

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairComparator> pq;

        int arr_size = points.size();
        for (int i = 0; i < arr_size; i++){
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({ distance, i });
        }

        std::vector<std::vector<int>> k_closest_points;
        while (k > 0) {
            int point_index = pq.top().second;
            pq.pop();
            k_closest_points.push_back(points[point_index]);
            k--;
        }

        return k_closest_points;
    }
};
