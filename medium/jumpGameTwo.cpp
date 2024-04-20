#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int max_reachable_ind = 0;
        int new_max_reachable_ind = 0;
        int n = nums.size();
        int steps = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i > max_reachable_ind) {
                max_reachable_ind = new_max_reachable_ind;
                steps += 1;
            }
            new_max_reachable_ind = std::max(new_max_reachable_ind, nums[i] + i);                 
        }
        return steps; 
    }
};

int main() {
    std::vector a {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};

    Solution sol;
    std::cout << sol.jump(a) << '\n';
}