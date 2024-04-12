#include <algorithm>

class Solution {
public:
    double myPow(double x, int n) {
        int exp = std::abs(n);
        double result = 1;
        double multiplier = x;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= multiplier;
            }
            multiplier *= multiplier;
            exp /= 2;
        }
        if (n < 0) result = 1.0 / result;

        return result;
    }
};

int main() {
    Solution sol;

    sol.myPow(2.0, 10);
}