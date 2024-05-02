#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        unordered_map<int, vector<int>> m; 
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!canFinish(m, result, i)) return {};
        } 
        return result;
    }
private:
    bool canFinish(unordered_map<int, vector<int>>& m, vector<int>& res, int key) {
        if (m[key].empty()) {
            m[key] = {-2};
            res.push_back(key);
            return true;
        }
        if (m[key][0] == -2) return true;
        if (m[key][0] == -1) return false;
        vector<int> values = m[key];
        m[key] = {-1};
        for (const auto& n : values) {
            if (!canFinish(m, res, n)) return false;
        }
        res.push_back(key);
        m[key][0] = -2;
        return true;
    }
};