#include <stack>
#include <iostream>
#include <vector>
#include <set>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> intStack;
        std::set<std::string> opSet {"+", "-", "*", "/"};

        for (int i = 0; i < tokens.size(); i++) {
            if (opSet.find(tokens[i]) == opSet.end()) {
                intStack.push(std::stoi(tokens[i]));
            } else {
                int secondOperand = intStack.top();
                intStack.pop();
                int firstOperand = intStack.top();
                intStack.pop();

                if (tokens[i] == "+") intStack.push(firstOperand + secondOperand);
                else if (tokens[i] == "-") intStack.push(firstOperand - secondOperand);
                else if (tokens[i] == "*") intStack.push(firstOperand * secondOperand);
                else if (tokens[i] == "/") intStack.push(firstOperand / secondOperand);
            }
        }

        return intStack.top();
    }
};