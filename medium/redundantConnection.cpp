#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        unordered_set<int> s;
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (findCycle(m, s, edges[i], edges[i][1])) return edges[i];    
        }
        return {};
    }
private:
    bool findCycle(unordered_map<int, vector<int>>& m, unordered_set<int>& s, vector<int>& original_edge, 
                    int key) {
        s.insert(key);
        for (const auto& n : m[key]) {
            if (n == original_edge[0]) {
                if (key == original_edge[1]) continue;
                else return true;
            }
            if (s.find(n) != s.end()) continue;
            if (findCycle(m, s, original_edge, n)) return true;
        }
        s.erase(key);
        return false;
    }
};