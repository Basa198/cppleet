#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
    
        int maxVol = 0;

        while (start < end) {
            int curVol = (end - start) * std::min(height[start], height[end]);
            if (curVol > maxVol) maxVol = curVol;

            if (height[start] < height[end]) {
                int k = start + 1;

                while (k < end && height[k] <= height[start]) k++;
                start = k;
            } else {
                int k = end - 1;
                
                while (k > start && height[k] <= height[end]) k--;
                end = k;
            }
        }

        return maxVol;
    }
};