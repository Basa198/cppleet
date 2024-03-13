#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if (strs.size() == 0) return {{""}};

        std::unordered_map<std::string, std::vector<std::string>> hashMap;

        int strsLength = strs.size();
        for (int i = 0; i < strsLength; i++) {
            std::vector<int> letterArray(26, 0);

            for (int j = 0; j < strs[i].size(); j++) {
                letterArray[strs[i][j] - 'a'] += 1;
            }

            std::stringstream ss;
            for (int j = 0; j < letterArray.size(); j++) {
                ss << letterArray[j];
                ss << '#';
            }
            
            std::string strNumericRep = ss.str();
            hashMap[strNumericRep].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> returnArray;
        for (const auto& pair : hashMap) {
            returnArray.push_back(pair.second);
        }

        return returnArray;
    }
};

int main() {
    Solution sol;
    // std::vector<std::string> a1 {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::string> a1 {"bdddddddddd", "bbbbbbbbbbc"};

    auto res = sol.groupAnagrams(a1);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
