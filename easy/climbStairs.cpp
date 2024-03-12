#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= this->cache.size()) {
            return this->cache[n - 1]; 
        }

        for (int i = this->cache.size(); i < n; i++) {
            this->cache.push_back(this->cache[i - 1] + this->cache[i - 2]);
            std::cout << this->cache[i] << '\n';
        }

        return this->cache[n - 1];
    }
private:
    std::vector<int> cache {1, 2, 3};
};


int main() {
    Solution sol;

    std::cout << sol.climbStairs(45) << '\n';
}