#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int index = 1;
        int prevElement = nums[0];
        
        int length = nums.size(); 
        for (int i = 1; i < length; i++) {
            if (nums[i] != prevElement) {
                prevElement = nums[i];
                nums[index++] = prevElement;
            }
        }
     
        return index;
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 = {0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 6};

    int count = sol.removeDuplicates(a1);

    for (int i = 0; i < count; i++) {
        std::cout << a1[i];
    }

    std::cout << '\n' << count << '\n';
}