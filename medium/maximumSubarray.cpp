#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] = std::max(0, nums[i - 1]) + nums[i];                

            if (nums[i] > sum) sum = nums[i];
        }

        return sum;  
    }
};