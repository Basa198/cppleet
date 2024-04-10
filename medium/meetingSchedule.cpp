#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        sort(intervals.begin(), intervals.end());

        pq.push(intervals[0][1]);

        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }           

        return pq.size();
    }
};
