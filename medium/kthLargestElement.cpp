#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++){
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};