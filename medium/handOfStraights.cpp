#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        std::map<int, int> m;
        for (int i = 0; i < n; i++) m[hand[i]]++;

        while (!m.empty()) {
            int current = m.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (m[current + i] == 0) return false;
                m[current + 1]--;
                if (m[current + 1] <= 0) m.erase(current + 1);
            }
        }
        return true;
    }
};

int main() {
    std::vector a {2, 3, 3, 4};
    Solution sol;
    sol.isNStraightHand(a, 3);
}   