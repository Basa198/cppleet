#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0) return 0;

        int left = 0;
        int right = 1;
        int n = s.size();
        int max = 1;
        std::unordered_map<char, int> map;
        map[s[left]] = 0;

        while (right < n) {
            if (map.find(s[right]) != map.end() && map[s[right]] >= left) {
                left = map[s[right]] + 1;
                map[s[right]] = right;
            } else {
                map[s[right]] = right;
                max = std::max(max, right - left + 1);
            }
            right++;
        }

        return max;
    }
};

int main() {
    Solution sol;

    std::cout << sol.lengthOfLongestSubstring("aab") << '\n';;
}