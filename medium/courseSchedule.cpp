#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (const auto& pair : m) {
            if (!canFinish(m, pair.first)) return false;
        } 
        return true;
    }
private:
    bool canFinish(unordered_map<int, vector<int>>& m, int key) {
        if (m[key].empty()) return true;
        if (m[key][0] == -1) return false;
        vector<int> values = m[key];
        m[key] = {-1};
        for (const auto n : values) {
            if (!canFinish(m, n)) return false;
        }
        m[key].clear(); 
        return true;
    }
};