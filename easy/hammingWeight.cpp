#include <iostream>

class Solution {
public:
    int hammingWeight(std::uint32_t n) {
        int count = 0;

        while (n) {
            ++count;

            n = n & (n - 1);
        }

        return count;
    }

    int hammingWeight2(std::uint32_t n) {
        int bit = 0;
        int res = 0;

        while (n) {
            bit = n & 1;
            if (bit == 1) res++;
            n >>= 1;
        }

        return res;
    }
};