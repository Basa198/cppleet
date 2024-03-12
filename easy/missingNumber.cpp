#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 {1, 3, 0};

    std::cout << sol.missingNumber(a1) << '\n';
}