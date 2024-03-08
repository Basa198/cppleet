#include <string>
#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int index = s.length() - 1;

        while (s[index] == ' ') {
            index--;
        }

        int count = 0;

        while (index >= 0 && s[index--] != ' ') {
            count++;
        }

        return count;
    }
};


int main() {
    Solution sol;
    std::string s1 = "   fly me   to   the moon  ";

    std::cout << sol.lengthOfLastWord(s1) << '\n';
}