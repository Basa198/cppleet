#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> hashmap = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        
        int strLength = s.length() - 1; // Taking length - 1 from the beginning, to avoid doing it every time
        int total = 0;
        int prevVal = 0; // need to be smaller than any possible roman numerical

        for (int i = strLength; i > -1; i--) {
            int curVal = hashmap[s[i]];
            if (curVal < prevVal) {
                total -= curVal;
            } else {
                total += curVal;
            }
            prevVal = curVal;
        }

        return total;
    }
};


int main() {
    Solution sol;
    std::string s1 = "MCMXCIV";

    std::cout << sol.romanToInt(s1) << '\n';
}

