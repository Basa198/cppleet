#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};


int main() {
    Solution sol;
    std::vector a1 = {9, 9};

    std::vector<int> res = sol.plusOne(a1);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];
    }
    std::cout << '\n';
}