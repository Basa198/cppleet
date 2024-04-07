#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> sbs;
        sbs.push_back({});
        std::vector<int> curr;
        subsets(nums, sbs, curr, 0);
        return sbs;
    }

private:
    void subsets(std::vector<int>& nums, std::vector<std::vector<int>>& sbs, std::vector<int>& curr, int index) {
        if (index == nums.size()) return;
        int nums_size = nums.size();
        for (int i = index; i < nums_size; i++) {
            curr.push_back(nums[i]);
            sbs.push_back(curr);
            subsets(nums, sbs, curr, i + 1);
            curr.pop_back();
        }
    }
};