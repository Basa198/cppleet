#include <cmath>
#include <iostream>
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int sign = x < 0 ? -1 : 1;
        x = std::abs(x);
        while (x > 0) {
            int t = x % 10;
            x /= 10;
            if (res > 214748364 || (res == 214748364 && t > 7)) return 0;
            res = res * 10 + t;
        }
        return res * sign;
    }
};