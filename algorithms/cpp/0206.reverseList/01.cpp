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
        if (!head || !head->next) return head;
        
        ListNode* l = head;
        ListNode* m = head->next;
        ListNode* r;
        
        while (m && m->next) {
            r = m->next;
            m->next = l;
            l = m;
            m = r;
        }
        
        m->next = l;
        head->next = NULL;
        return m;
    }
};
