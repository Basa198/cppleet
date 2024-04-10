#include <vector>
#include <algorithm>
class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int count = 0;
        std::sort(intervals.begin(), intervals.end());

        auto cur_interval = intervals[0];
        int i = 1;
        while (i < intervals.size()) {
            if (cur_interval[1] > intervals[i][0]) {
                count++;
                cur_interval = cur_interval[1] > intervals[i][1] ? intervals[i] : cur_interval;
            } else {
                cur_interval = intervals[i];
            }
            i++;
        }

        return count;
    }
};