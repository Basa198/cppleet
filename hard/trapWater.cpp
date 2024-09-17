#include <vector>
#include <algorithm>

class Solution {
public:
  // int trap(std::vector<int>& height) {
  //   int total = 0;        
  //   int low = 0; 
  //   while (low < height.size() && height[low] == 0) low++;
  //   int high = low + 1;
  //   while (low < high && high < height.size()) {
  //     int max_index = high; 
  //     while (high < height.size() && height[low] > height[high]) {
  //       if (height[high] > height[max_index]) max_index = high;
  //       high++;
  //     }
  //     if (high == height.size()) high = max_index;
  //     int cur_total = std::min(height[low], height[high]) * (high - low - 1);
  //     int i = low + 1;
  //     while (i != high) {
  //       cur_total -= height[i++];
  //     }
  //     low = high;
  //     high = low + 1;
  //     total += cur_total;
  //   }
  //   return total;
  // }

  int trap(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int total = 0;

    while (left < right) {
      if (leftMax < rightMax) {
        leftMax = std::max(leftMax, height[++left]);
        total += leftMax - height[left];
      } else {
        rightMax = std::max(rightMax, height[--right]);
        total += rightMax - height[right];
      }
    }
    return total;
  }
};