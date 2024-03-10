#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> diffMap; // hashmap with difference as the key and index as a value

        int arrLength = nums.size();

        for (int i = 0; i < arrLength; i++) {
            if (diffMap.find(nums[i]) != diffMap.end()) {
                int index = diffMap[nums[i]];
                return std::vector {index, i};
            }
            diffMap[target - nums[i]] = i;     
        }         

        return std::vector {0, 0};
    }
};


int main() {
    Solution sol;
    std::vector a1 = {2, 7, 11, 15};
    int target = 17;

    std::vector returnVal = sol.twoSum(a1, target);
    std::cout << returnVal[0] << ' ' << returnVal[1] << '\n';
}
    