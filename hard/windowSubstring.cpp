#include <string>
#include <unordered_map>
#include <limits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
      if (t.size() > s.size()) return "";
      int min_window[2] = {0, std::numeric_limits<int>::max()};
      int start_index = 0;
      std::unordered_map<char, int> map;
      for (char c : t) map[c]++;
      int remaining_chars = t.size();  

      for (int end_index = 0; end_index < s.size(); end_index++) {
        if (map.find(s[end_index]) != map.end() && map[s[end_index]] > 0) remaining_chars--;
        map[s[end_index]]--;

        if (remaining_chars == 0) {
          while (true) {
            if (map.find(s[start_index]) != map.end() && map[s[start_index]] == 0) break;
            map[s[start_index++]]++;
          }
          if (end_index - start_index < min_window[1] - min_window[0]) {
            min_window[0] = start_index; 
            min_window[1] = end_index;
          }
          map[s[start_index++]]++;
          remaining_chars++;
        }
      }
      return min_window[1] > s.size() ? "" : s.substr(min_window[0], min_window[1] - min_window[0] + 1);
    }
};