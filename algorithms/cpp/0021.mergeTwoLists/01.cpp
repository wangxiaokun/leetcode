#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class SingleLinkedList
{
public:
    SingleLinkedList():pHead_(NULL),pTail_(NULL) {}
    
    // 节点插入到头部
    void addToHead(int val)
    {
        ListNode* p = new ListNode(val);
        p->next = pHead_;
        pHead_ = p;
        if (!pTail_) pTail_ = pHead_;
    }
    
    // 节点插入到尾部
    void addToTail(int val)
    {
        ListNode* p = new ListNode(val);
        if (!pTail_) {
            pHead_ = pTail_ = p;
        }
        else {
            pTail_->next = p;
            pTail_ = p;
        }
    }
    
    // 从头部删除节点
    void delFromHead() {}
    
    // 从尾部删除节点
    void delFromTail() {}

    // 删除指定节点
    void delNode(ListNode* p) {}
    
    // 删除指定节点
    void delNode(int val) {}
    
    // 获取头结点
    ListNode* getHead() {return pHead_;}
    
private:
    ListNode* pHead_;
    ListNode* pTail_;
};



string listNodeToString(ListNode* node);


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        while (l1 || l2)
        {
            if (l1 && !l2)
            {
                singleLinkedList.addToTail(l1->val);
                l1 = l1->next;
            }
            else if (!l1 && l2)
            {
                singleLinkedList.addToTail(l2->val);
                l2 = l2->next;
            }
            else
            {
                if (l1->val <= l2->val)
                {
                    singleLinkedList.addToTail(l1->val);
                    l1 = l1->next;
                }
                else
                {
                    singleLinkedList.addToTail(l2->val);
                    l2 = l2->next;
                }
            }
        }

        return singleLinkedList.getHead();
    }

private:
    SingleLinkedList singleLinkedList;
};




void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
