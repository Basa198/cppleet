#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> new_intervals;
        int i = 0;
        int intervals_size = intervals.size();
        while (i < intervals_size && newInterval[0] > intervals[i][0]) {
            new_intervals.push_back(intervals[i]);
            i++;
        }
        if (i > 0 && intervals[i - 1][1] >= newInterval[0]) {
            new_intervals.pop_back();
            newInterval[0] = intervals[i - 1][0];
            newInterval[1] = std::max(intervals[i - 1][1], newInterval[1]);
        }
        while (i < intervals_size && intervals[i][0] <= newInterval[1]) {
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            i++;
        }
        new_intervals.push_back(newInterval);
        while(i < intervals_size) {
            new_intervals.push_back(intervals[i]);
            i++;
        }
        return new_intervals;
    }
};