#include <vector>
#include <iostream>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int majorityCandidate = nums[0];
        int count = 1;

        int length = nums.size();
        for (int i = 1; i < length; i++) {
            if (majorityCandidate == nums[i]) {
                count++;
            } else {
                count--;

                if (count == 0) {
                    majorityCandidate = nums[i];
                    count = 1;
                }
            }
        }

        return majorityCandidate;
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 = {3, 2, 3};
    // std::vector<int> a1 = {3, 3, 1, 1, 1, 3, 3};

    std::cout << sol.majorityElement(a1) << '\n';
}

