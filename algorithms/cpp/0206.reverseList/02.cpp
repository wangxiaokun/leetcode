/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        
        ListNode* newhead = head;
        ListNode* p = head;
        
        while (head->next) {
            p = head->next;
            head->next = p->next;
            p->next = newhead;
            newhead = p;
        }
        return newhead;
    }
};
