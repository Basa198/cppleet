#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int next0 = 0;
        int prev0 = 0;
        int cur0 = 0;
        int next1 = 0;
        int prev1 = 0;
        int cur1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                next0 = std::max(cur0, prev0 + nums[i]);
                prev0 = cur0;
                cur0 = next0;
            } else if (i == n - 1) {
                next1 = std::max(cur1, prev1 + nums[i]);
                prev1 = cur1;
                cur1 = next1;
            } else {
                next0 = std::max(cur0, prev0 + nums[i]);
                prev0 = cur0;
                cur0 = next0;
                next1 = std::max(cur1, prev1 + nums[i]);
                prev1 = cur1;
                cur1 = next1;
            }
        }

        return std::max(cur0, cur1);
    }
};