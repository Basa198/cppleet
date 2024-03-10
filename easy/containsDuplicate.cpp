#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> numSet;
        
        int numsLength = nums.size();
        for (int i = 0; i < numsLength; i++) {
            if (numSet.count(nums[i])) {
                return true;
            }
            numSet.insert(nums[i]);
        }

        return false;
    }
};


int main() {
    Solution sol;
    std::vector a1 {1, 2, 3, 4};

    std::cout << sol.containsDuplicate(a1) << '\n';
}