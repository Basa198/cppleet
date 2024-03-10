#include <string>
#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int strLength = s.size();
        if (strLength != t.size()) return false;

        int letterCount[26] = {};

        for (int i = 0; i < strLength; i++) {
                int alphabetNum1 = s[i] - 97;
                int alphabetNum2 = t[i] - 97;

                letterCount[alphabetNum1]++;
                letterCount[alphabetNum2]--;
        }

        for (int i = 0; i < 26; i++) {
            if (letterCount[i] != 0) return false;
        }

        return true;
    }
};


int main() {
    Solution sol;
    std::string t = "rat";
    std::string s = "car";

    std::cout << sol.isAnagram(t, s) << '\n';
}