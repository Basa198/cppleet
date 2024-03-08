#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int length = strs.size() - 1;
        int prefixLength = strs[length].length();

        for (int i = length; i > 0; i--) {
            if (prefixLength == 0) {
                break;
            }


            std::string curString = strs[i];
            std::string nextString = strs[i - 1];
            int minLength = std::min(prefixLength, (int) curString.size());
            minLength = std::min(minLength, (int) nextString.size()); 
            
            int newPrefixLength = 0;
            for (int j = 0; j < minLength; j++) {
                if (curString[j] == nextString[j]) {
                    newPrefixLength++;
                } else {
                    break;
                }
            }

            if (prefixLength > newPrefixLength) {
                prefixLength = newPrefixLength;
            }
        }

        return strs[0].substr(0, prefixLength);
    }
};


int main() {
    Solution sol;
    std::vector<std::string> a1 {"dog", "racecar", "car"};

    std::cout << sol.longestCommonPrefix(a1) << '\n'; 
}