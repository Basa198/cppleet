#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>

class Solution {
public:
    int getSum(int a, int b) {
        int c_in = 0;
        int res = 0;
        int i = 0;
        while (i < 32) {
            int a_bit = a & 1;
            int b_bit = b & 1;
            a >>= 1;
            b >>= 1;
            res |= (a_bit ^ b_bit ^ c_in) << i;
            c_in = a_bit & b_bit | c_in & (a_bit ^ b_bit);
            ++i;
        }
        return res;
    }
};

int main() {
    int a = 5;
    int b = -105;
    std::bitset<32> bits(a);
    std::cout << bits << '\n';
    std::cout << std::bitset<32>(b) << '\n';
    Solution sol;
    std::cout << sol.getSum(a, b) << '\n';
}