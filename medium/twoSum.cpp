#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::unordered_map<int, int> diffMap; // hashmap with difference as the key and index as a value

        int arrLength = numbers.size();

        for (int i = 0; i < arrLength; i++) {
            if (diffMap.find(numbers[i]) != diffMap.end()) {
                int index = diffMap[numbers[i]];
                return std::vector{index + 1, i + 1};
            }
            diffMap[target - numbers[i]] = i;
        }

        return std::vector{0, 0};
    }
};