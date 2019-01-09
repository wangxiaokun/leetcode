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

void setCycle(ListNode* head, int pos)
{
    if (!head) return;
    if (pos == -1) return;

    ListNode* tail = getTailByHead(head);
    ListNode* tmp = head;
    for (int i=0; i<pos; ++i) {
        tmp = tmp->next;
    }
    tail->next = tmp;
}

class Solution {
public:
    bool hasCycle(ListNode *head, int pos) {
        printListNode(head);
        setCycle(head, pos);
        printListNode(head);

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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int pos = stringToInteger(line);
        
        bool ret = Solution().hasCycle(head, pos);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
