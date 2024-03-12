#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> cummulativeCost { 0, 0 };

        int costArrLength = cost.size();
        for (int i = 2; i <= costArrLength; i++) {
            int firstOption = cummulativeCost[i - 2] + cost[i - 2];
            int secondOption = cummulativeCost[i - 1] + cost[i - 1];

            cummulativeCost.push_back(std::min(firstOption, secondOption));
        }


        return cummulativeCost[costArrLength];
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 = {1,100,1,1,1,100,1,1,100,1};

    std::cout << sol.minCostClimbingStairs(a1) << '\n';
}