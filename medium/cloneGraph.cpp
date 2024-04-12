#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        std::unordered_map<Node*, Node*> map;        
        cloneGraph(node, map);
        return map[node];
    }
private:
    void cloneGraph(Node* node, std::unordered_map<Node*, Node*>& map) {
        Node* new_node = new Node(node->val);
        map[node] = new_node;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (map.find(node->neighbors[i]) == map.end()) {
                cloneGraph(node->neighbors[i], map);
                
            }
            new_node->neighbors.push_back(map[node->neighbors[i]]);
        }
    }
};