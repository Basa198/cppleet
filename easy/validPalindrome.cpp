#include <string>
#include <iostream>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int strLength = s.size();
        int lIndex = 0;
        int rIndex = strLength - 1;

        while (lIndex < rIndex) {
            if (!isalnum(s[lIndex])) {
                lIndex++;
                continue;
            }
            if (!isalnum(s[rIndex])) {
                rIndex--;
                continue;
            } 

            if (std::tolower(s[lIndex]) != std::tolower(s[rIndex])) return false;
            lIndex++;
            rIndex--;
        }
        return true;
    }
};


int main() {
    Solution sol;
    std::string s1 = "race a car";

    std::cout << sol.isPalindrome(s1) << '\n';
}