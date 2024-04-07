#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> permutations;
        std::vector<bool> used(nums.size());
        std::vector<int> curr;
        permute(nums, permutations, used, curr);
        return permutations;
    }

private:
    void permute(std::vector<int>& nums, std::vector<std::vector<int>>& permutations, std::vector<bool>& used, std::vector<int>& curr) {
        if (curr.size() == nums.size()) {
            permutations.push_back(curr);
            return;
        }
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            if (!used[i]) {
                used[i] = true;
                curr.push_back(nums[i]);
                permute(nums, permutations, used, curr);
                curr.pop_back();
                used[i] = false;
            }
        } 
    }
};