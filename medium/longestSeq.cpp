#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int max = 0;
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
          if (map.find(nums[i]) != map.end()) continue;
          int left = map.find(nums[i] - 1) != map.end() ? map[nums[i] - 1] : 0;
          int right = map.find(nums[i] + 1) != map.end() ? map[nums[i] + 1] : 0;
          int total_length = left + right + 1;
          map[nums[i]] = map[nums[i] - left] = map[nums[i] + right] = total_length;
          max = std::max(max, total_length);
        }
        return max;
    }
};  