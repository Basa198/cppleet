#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> connection;
        vector<int> connection_freq(n + 1, 1);
        for (int i = 0; i < n + 1; i++) connection.push_back(i);
        for (int i = 0; i < n; i++) {
            if (doUnion(connection, connection_freq, edges[i])) return edges[i];
        }
        return {};
    }
private:
    int doFind(vector<int> connections, int n) {
        int c = connections[n];
        while (c != connections[c]) {
            connections[c] = connections[connections[c]];
            c = connections[c];
        }
        return c;
    }
    bool doUnion(vector<int>& connections, vector<int>& freq, vector<int>& edge) {
        int n1 = doFind(connections, edge[0]);
        int n2 = doFind(connections, edge[1]);
        if (n1 == n2) return true;
        if (freq[n1] > freq[n2]) {
            connections[n2] = n1;
            freq[n1] += freq[n2];
        } else {
            connections[n1] = n2;
            freq[n2] += freq[n1];
        }
        return false;
    }
};

int main() {
    vector<vector<int>> a {{1, 2}, {2, 3}, {3, 4}, {1,4}, {1,5}};
    Solution sol;
    sol.findRedundantConnection(a);
}