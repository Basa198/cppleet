#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> map;

        Node* original = head;

        while (original) {
            map[original] = new Node(original->val);
            original = original->next;
        }

        original = head; // set it back to head to iterate again
        while (original) {
            Node* newNode = map[original];
            newNode->next = map[original->next];
            newNode->random = map[original->random];
            original = original->next;
        }

        return map[head];
    }
};