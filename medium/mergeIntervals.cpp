#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;

        int i = 1;
        auto cur_interval = intervals[0];
        while (i < intervals.size()) {
            if (cur_interval[1] >= intervals[i][0]) {
                cur_interval[1] = std::max(intervals[i][1], cur_interval[1]);
            } else {
                ans.push_back(cur_interval);
                cur_interval = intervals[i];
            }
            i++;
        }
        ans.push_back(cur_interval);
        return ans; 
    }
};