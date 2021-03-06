#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    if (input.empty()) return nullptr;
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree"<<endl;
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}


class Solution {
public:
    // Recursive solution is trivial, could you do it iteratively?
    // 思考
    // 1.递归方式，代码简洁，易懂，框架清晰
    // 2.遍历方式，其实也是利用了递归的思想，只是需要自己处理栈，
    // 而递归方式是利用了程序本身函数调用时就要入栈出栈
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        
        preorderTraversal_recursively(root, vec);
        cout<<"recursively:"<<endl;
        for (int i : vec) cout<<i<<" ";
        cout<<endl;
        
        vec.clear();
        preorderTraversal_iteratively(root, vec);
        cout<<"iteratively:"<<endl;
        for (int i : vec) cout<<i<<" ";
        cout<<endl;
        
        return vec;
    }
    
    void preorderTraversal_iteratively(TreeNode* root, vector<int>& vec) {
        TreeNode* tmp = root;
        stack<TreeNode*> st;
        while (tmp) {
            vec.push_back(tmp->val);
            if (tmp->left) {
                if (tmp->right) st.push(tmp);
                tmp = tmp->left;
            }
            else if (tmp->right) {
                tmp = tmp->right;
            }
            else {
                if (st.empty()) break;
                tmp = st.top();
                st.pop();
                tmp = tmp->right;
            }
        }
    }
    
    void preorderTraversal_recursively(TreeNode* root, vector<int>& vec) {
        if (root) vec.push_back(root->val);
        else return;
        preorderTraversal_recursively(root->left, vec);
        preorderTraversal_recursively(root->right, vec);
    }
};

// []
// [1]
// [1,2]
// [1,null,2]
// [1,2,3,4,5,6,7]
// [1,2,null,3,4]
// [1,null,2,3]

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        prettyPrintTree(root);
        
        Solution solution;
        solution.preorderTraversal(root);
    }
    return 0;
}