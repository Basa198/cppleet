#include <iostream>
#include <vector>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(std::vector<Interval>& intervals) {
        int vecLength = intervals.size();
        for (int i = 0; i < vecLength - 1; i++) {
            int start = intervals[i].start;
            int end = intervals[i].end; 

            for (int j = i + 1; j < vecLength; j++) {
                if (start >= intervals[j].end || end <= intervals[j].start) continue;
                else return false;
            }
        }

        return true;
    }
};
