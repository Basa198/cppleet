#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> letters(26);
        int left = 0;
        int right = 0;
        int result = 0;
        int maxCount = 0;

        while (right < s.size()) {
            letters[s[right] - 'A']++;
            maxCount = std::max(maxCount, letters[s[right] - 'A']);

            if (right - left + 1 - maxCount > k) {
                letters[s[left] - 'A']--;
                left++;
            }
            result = std::max(result, right - left + 1);
            right++;
        }
        
        return result;
    }
};