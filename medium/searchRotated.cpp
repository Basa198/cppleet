#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < nums[r]) {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            } else {
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
        }

        return -1;
    }
};


int main() {
    Solution sol;

    std::vector<int> a1 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << sol.search(a1, 0) << '\n';
}