#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> connections;
        vector<int> freq(n, 1);
        for (int i = 0; i < n; i++ ) { connections.push_back(i); }
        for (int i = 0; i < m; i++) doUnion(connections, freq, edges[i]); 
        int count = 0;
        for (int i = 0; i < n; i++) 
            if (freq[i] > 0) count++;
        return count;
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
    void doUnion(vector<int>& connections, vector<int>& freq, vector<int>& edge) {
        int n1 = doFind(connections, edge[0]);
        int n2 = doFind(connections, edge[1]);
        if (n1 == n2) return;
        freq[n2] += 1;
        freq[n1] = 0;
        connections[n1] = n2;
    }
};

int main() {
    vector<vector<int>> edges {{0,1}, {1,2}, {2,3}, {4,5}};
    Solution sol;
    sol.countComponents(6, edges);
}