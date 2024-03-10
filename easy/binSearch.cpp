#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lIndex = 0;
        int rIndex = nums.size() - 1;

        while (lIndex <= rIndex) {
            int m = (lIndex + rIndex) / 2;
            if (target == nums[m]) return m;
            if (target < nums[m]) {
                rIndex = m - 1;
            } else {
                lIndex = m + 1;
            }
        }

        return -1;
    }
};


int main() {
    Solution sol;
    std::vector a1 = {-1, 0, 3, 5, 9, 12};
    int target = 12;

    std::cout << sol.search(a1, target) << '\n';
}
