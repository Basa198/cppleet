#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() == 1) return false;
        std::vector<char> stack;
        std::unordered_map<char, char> parenMap = { {'}', '{'}, {']', '['}, {')', '('} };
        int count = 0;

        int strLength = s.size();
        for (int i = 0; i < strLength; i++) {
            if (parenMap.find(s[i]) == parenMap.end()) {
                stack.push_back(s[i]);
                count++;
            } else {
                char p = parenMap[s[i]];
                if (count == 0 || stack[count - 1] != p) return false;
                count--;
                stack.pop_back();
            }
        }

        return count == 0;
    }
};


int main() {
    Solution sol;
    std::string s1 = "(())";

    std::cout << sol.isValid(s1) << '\n';
}