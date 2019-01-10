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

inline void delNode(ListNode* node) {
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
        ListNode* pretail = head;   // 新增一个空间用于存储tail节点的前一个节点，方便删除tail节点，空间复杂度为常量级别
        while (tmp) {
            if (tmp->val == val) {
                if (tmp->next) {
                    delNode(tmp);
                }
                else {
                    delTailNode(pretail);
                    if (tmp == head) head = NULL;
                    break;
                }
            }
            else {
                pretail = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
