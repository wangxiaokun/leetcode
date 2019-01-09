/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void printListNode(ListNode* head)
{
    cout<<endl<<"-----------------------------------------------------------"<<endl;
    ListNode* tmp = head;
    int i=0;
    while (tmp) {
        cout<<"--> val("<<tmp->val<<")\tnext("<<tmp->next<<")"<<endl;
        tmp = tmp->next;
        if (++i>30) {
            cout<<"maybe has cycle"<<endl;
            break;
        }
    }
    cout<<"-----------------------------------------------------------"<<endl<<endl;
}

void delNode(ListNode* node) {
    if (node->next) {
        ListNode* tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;   
    }
}

void delTailNode(ListNode* head) {
    if (head) {
        ListNode* tmp = head;
        ListNode* tail = head;
        while (tail) {
            if (!tail->next) {
                tmp->next = NULL;
                delete tail;
                break;
            }
            else {
                tmp = tail;
                tail = tail->next;
            }
        }
    }
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode* tmp = head;
        while (tmp) {
            if (tmp->val == val) {
                if (tmp->next) {
                    delNode(tmp);
                }
                else {
                    delTailNode(head);
                    if (tmp == head) head = NULL;
                    break;
                }
            }
            else {
                tmp = tmp->next;
            }
        }
        return head;
    }
};


