#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int duration = temperatures.size();
        std::vector<int> answer(duration);
        std::stack<std::pair<int, int>> stk; // [temp, index]

        for (int i = duration - 1; i >= 0; i--) {
            while(!stk.empty() && temperatures[i] >= stk.top().first) {
                stk.pop();
            }
            if (stk.empty()) {
                answer[i] = 0;
            } else {
                answer[i] = stk.top().second - i;
            }
            stk.push({temperatures[i], i});
        }

        return answer;
    }
};