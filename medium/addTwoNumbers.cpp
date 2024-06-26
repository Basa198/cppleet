struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();

        bool carry = 0;
        ListNode* cur = head;

        while (l1 || l2) {
            int sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            cur->val = sum % 10;
            carry = sum / 10;

            if (l1 && l1->next || l2 && l2->next) {
                ListNode* newNode = new ListNode();
                cur->next = newNode;
                cur = newNode;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }    

        if (carry) {
            cur->next = new ListNode(1);
        }
        
        return head;
    }
};