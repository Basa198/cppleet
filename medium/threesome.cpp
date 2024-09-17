#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int low = i + 1;
            int high = nums.size() - 1;
            
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    
                    while (low + 1 < nums.size() && nums[low] == nums[low + 1]) low++;
                    while (high >= 1 && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                } else if (sum < 0) low++;
                else high--;
            }
        }
        return res;
    }
};
