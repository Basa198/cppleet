#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> set;

        while (n != 1) {
            n = getNext(n);
            if (set.count(n) > 0) return false;

            set.insert(n);
        }

        return true;
    }

private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += std::pow(digit, 2);
        }
        return sum;
    }
};


int main() {
    Solution sol;
    
    std::cout << sol.isHappy(19) << '\n';
}