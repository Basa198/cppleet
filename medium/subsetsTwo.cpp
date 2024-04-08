#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> sbs;
        sbs.push_back({});
        std::vector<int> curr;
        subsets(nums, sbs, curr, 0);
        return sbs;
    }
private:
    void subsets(std::vector<int>& sorted_nums, std::vector<std::vector<int>>& sbs, std::vector<int>& curr, int index) {
        int nums_size = sorted_nums.size();
        for (int i = index; i < nums_size; i++) {
            if (i > index && sorted_nums[i] == sorted_nums[i - 1]) continue;

            curr.push_back(sorted_nums[i]);
            sbs.push_back(curr);
            subsets(sorted_nums, sbs, curr, i + 1);
            curr.pop_back();
        }
    } 
};

int main() {
    Solution sol;
    std::vector<int> a1 {1, 2, 2};

    sol.subsetsWithDup(a1);
}