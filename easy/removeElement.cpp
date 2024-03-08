#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int index = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }

        return index;
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 = {0, 1, 1, 2, 3, 5, 4, 1, 2, 6, 3};
    int val = 1;

    int count = sol.removeElement(a1, val);

    for (int i = 0; i < count; i++) {
        std::cout << a1[i];
    }

    std::cout << '\n' << count << '\n';
    
}