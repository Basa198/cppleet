#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // find the start of the second half of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        // reverse second part
        ListNode* prev = nullptr;
        while (mid) {
            ListNode* next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        mid = prev;

        // merge the first part (starts with head) with the second part (starts with mid) 
        while(mid) {
            ListNode* headNext = head->next;
            ListNode* midNext = mid->next;
            head->next = mid;
            mid->next = headNext;
            head = headNext;
            mid = midNext;
        }
    }
};