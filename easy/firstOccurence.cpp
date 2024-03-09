#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int needleLength = needle.size();
        int haystackLength = haystack.size();

        for (int i = 0; i < haystackLength; i++) {
            int k = i;
            int j = 0;

            while (haystack[k] == needle[j]){
                k++;
                j++;
                if (k >= haystackLength || j >= needleLength) break;
            }
            if (j == needleLength) return i;
        }

        return -1;
    }
};


int main() {
    Solution sol;
    std::string hay= "sadbutsad";
    std::string needle = "but";

    std::cout << sol.strStr(hay, needle) << '\n';
}
