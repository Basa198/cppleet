#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }

        return res;
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 {0, 1, 3, 0, 1, 3};

    std::cout << sol.singleNumber(a1) << '\n';
}