#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        std::priority_queue<int> pq;
        
        int numberOfStones = stones.size();
        for (int i = 0; i < numberOfStones; i++) pq.push(stones[i]);

        while (pq.size() > 1) {
            int firstStone = pq.top();
            pq.pop();
            int secondStone = pq.top();
            pq.pop();
            std::cout << firstStone << secondStone << '\n';

            int difference = firstStone - secondStone;
            if (difference > 0) pq.push(difference);
        }

        
        return pq.size() > 0 ? pq.top() : 0;
    }
};


int main() {
    Solution sol;
    std::vector a1 = {2, 7, 4, 1, 8, 1};

    std::cout << sol.lastStoneWeight(a1) << '\n';
}