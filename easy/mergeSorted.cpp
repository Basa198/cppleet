#include <vector>
#include <iostream>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int mainIndex = m + n - 1;
        int i_1 = m - 1;
        int i_2 = n - 1;

        while (mainIndex >= 0) {
            if (i_2 < 0) break;
            if (i_1 < 0) {
                nums1[mainIndex--] = nums2[i_2--];
            } else if (nums1[i_1] > nums2[i_2]) {
                nums1[mainIndex--] = nums1[i_1--];
            } else {
                nums1[mainIndex--] = nums2[i_2--];
            }

        }
    }
};


int main() {
    std::vector<int> a1 {1, 1, 3, 5, 0, 0, 0, 0};
    std::vector<int> a2 {0, 2, 4, 5};
    
    Solution sol;

    sol.merge(a1, 4, a2, 4);

    int length = a1.size();

    for (int i = 0; i < length; i++) {
        std::cout << a1[i];
    }
    std::cout << '\n';
}
    
