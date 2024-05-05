#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int max_cur = 1;
        int max_neg = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = nums[i] * max_cur;
            max_cur = std::max(std::max(nums[i] * max_neg, nums[i] * max_cur), nums[i]);
            max_neg = std::min(std::min(t, nums[i] * max_neg), nums[i]);
            max = std::max(max_cur, max);
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<int> a {2, 3, -2, 4};
    sol.maxProduct(a);
}