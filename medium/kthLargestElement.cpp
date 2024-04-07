#include <vector>
#include <queue>

// class Solution {
// public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

//         int nums_size = nums.size();
//         for (int i = 0; i < nums_size; i++){
//             pq.push(nums[i]);
//             if (pq.size() > k) pq.pop();
//         }

//         return pq.top();
//     }
// };
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, index, 0, nums.size() - 1);
    }
private:
    int quickSelect(std::vector<int>& nums, int k, int l, int r){
        int pivot = nums[r];
        int p_pos = l;
        for (int i = l; i < r; ++i){
            if (nums[i] <= pivot){
                swap(nums[i], nums[p_pos]);
                ++p_pos;
            }
        }
        swap(nums[p_pos], nums[r]);
        if (k < p_pos)
            return quickSelect(nums, k, l, p_pos - 1);
        if (k > p_pos)
            return quickSelect(nums, k, p_pos + 1, r);
        return nums[p_pos];
    }

    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
};