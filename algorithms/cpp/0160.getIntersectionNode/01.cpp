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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        // if (hasCycle(headA)) {
        //     // 有环
        // }
        // else {
            // 无环
            
            ListNode* tailB = getTailByHead(headB);
            tailB->next = headB;
            
            ListNode* tmp = hasCycleEx(headA);
            if (tmp) {
                // 有环即代表相交
                ListNode* tmp1 = headA;
                ListNode* tmp2 = tmp;
                
                while (tmp1 != tmp2) {
                    tmp1 = tmp1->next;
                    tmp2 = tmp2->next;
                }
                
                tailB->next = NULL;
                return tmp1;
            }
            tailB->next = NULL;
        // }
        return NULL;
    }
    
    
    
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
    
    ListNode* hasCycleEx(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return fast;
            }
        }

        return NULL;
    }

    ListNode* getTailByHead(ListNode* head)
    {
        ListNode* tail = head;
        while (tail) {
            if (!tail->next)
                break;
            else
                tail = tail->next;
        }

        return tail;
    }
    
    
    

    
};
