#include <vector>
#include <iostream>
#include <chrono>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buyPrice = prices[0];
        int maxProfit = 0;

        int length = prices.size();
        for (int i = 1; i < length; i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            } else if(prices[i] - buyPrice > maxProfit) {
                maxProfit = prices[i] - buyPrice;
            }
        }

        return maxProfit;
    }
};


int main() {
    Solution sol;
    std::vector<int> a1 = {7, 6, 4, 3, 1}; 

    std::cout << sol.maxProfit(a1) << '\n';
}