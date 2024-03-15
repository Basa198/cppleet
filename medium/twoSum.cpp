#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] > target) j--;
            else if (numbers[i] + numbers[j] < target) i++;
            else return {i + 1, j + 1};
        }

        return {-1, -1};
    }
};