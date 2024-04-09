#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0) return {};
        std::vector<std::string> combinations;
        std::string cur;
        letterCombinations(digits, combinations, 0, cur);
        return combinations;
    }
private:
    std::vector<std::string> mappings {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void letterCombinations(std::string digits, std::vector<std::string>& combinations, 
        int index, std::string& cur) {
        //
        if (cur.size() == digits.size()) {
            combinations.push_back(cur);
            return;
        }
        int digit = digits[index] - '0';
        for (int i = 0; i < mappings[digit - 2].size(); i++) {
            cur.push_back(mappings[digit - 2][i]);
            letterCombinations(digits, combinations, index + 1, cur);
            cur.pop_back();
        }
    }
};