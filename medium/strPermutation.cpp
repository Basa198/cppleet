#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::vector<int> letters(26, 0);
        int s1_size = s1.size();
        for (int i = 0; i < s1_size; i++) {
            ++letters[s1[i] - 'a'];
        }

        int l = 0;
        int m = l;
        int r = s1_size - 1;
        int s2_size = s2.size();

        while (r < s2_size) {
            while (m <= r && letters[s2[m] - 'a'] > 0) {
                --letters[s2[m] - 'a'];
                m++;
            }
            if (m > r) return true;

            while (s2[l] != s2[m]) {
                ++letters[s2[l] - 'a'];
                ++l;
                ++r;
            }
            ++r;
            ++l;
            ++m;
        }

        return false;
    }
};


int main() {
    std::string s1 = "hello";
    std::string s2 = "ooolleoooleh";

    Solution sol;

    std::cout << sol.checkInclusion(s1, s2) << '\n';
}