#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<std::string> generateParentheses(int n) {
        generateParentheses(n - 1, n, 1, "(");
        
        return validParenStrings;
    }

private: 
    std::vector<std::string> validParenStrings;

    void generateParentheses(int leftParen, int rightParen, int n, std::string parens) {
        if (leftParen == 0 && rightParen == 0) {
            validParenStrings.push_back(parens);
        } else if (leftParen == 0) {
            while (rightParen > 0) {
                parens += ")";
                rightParen--;
            }
            validParenStrings.push_back(parens);
        } else {
            generateParentheses(leftParen - 1, rightParen, n + 1, parens + "(");
            if (n > 0) {
                generateParentheses(leftParen, rightParen - 1, n - 1, parens + ")");
            }
        }
    }
};


int main() {
    Solution a;
    std::vector<std::string> res = a.generateParentheses(3); 

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << "\n";
    }
}