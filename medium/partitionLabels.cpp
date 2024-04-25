#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> last_index(26);        
        int n = s.size();
        for (int i = 0; i < n; i++) {
            last_index[s[i] - 'a'] = i;
        }
        std::vector<int> result;

        int cur_size = 0;
        int cur_last_ind = 0;
        for (int i = 0; i < n; i++) {
            cur_size++;
            cur_last_ind = std::max(cur_last_ind, last_index[s[i] - 'a']);
            if (i == cur_last_ind) {
                result.push_back(cur_size);
                cur_size = 0;
            }
        }

        return result;
    }
};