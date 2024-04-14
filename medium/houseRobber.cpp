#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int prev = 0;
        int cur = 0;
        int next = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            next = std::max(cur, prev + nums[i]);
            prev = cur;
            cur = next;
        }

        return cur;
    }
};

int main() {
    Solution sol;
    std::vector<int> a {2, 7, 9, 3, 1};
    sol.rob(a);
}
