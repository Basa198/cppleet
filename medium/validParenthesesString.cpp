#include <string>
#include <iostream>

class Solution {
public:
    bool checkValidString(std::string s) {
        int paren_count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') ++paren_count;
            else --paren_count;
            if (paren_count < 0) return false;
        }
        if (paren_count == 0) return true;
        paren_count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') ++paren_count;
            else --paren_count;
            if (paren_count < 0) return false;
        }
        return true;
    }
};

int main() {
    std::string a = "((()))()(())(*()()())**(())()()()()((*()*))((*()*)";
    Solution sol;
    sol.checkValidString(a);
}
