struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* next = head->next->next;

        while (next && next->next) {
            if (next == head) return true;
            head = head->next;
            next = next->next->next;
        }

        return false;
    }
};

