#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        int r1 = 1;
        int r2 = 1;

        std::vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            res[i] *= r1;
            r1 *= nums[i];

            res[n - i - 1] *= r2;
            r2 *= nums[n - i - 1];
        }

        return res;
    }
};