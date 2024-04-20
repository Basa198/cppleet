#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int ind_to_reach = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= ind_to_reach) ind_to_reach = i; 
        }   

        return ind_to_reach == 0;
    }
};