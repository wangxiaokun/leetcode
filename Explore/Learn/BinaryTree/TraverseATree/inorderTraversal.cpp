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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        vec.reserve(1024);
        
        inorderTraversal_recursively(root, vec);
        cout<<"recursively:"<<endl;
        for (int i : vec) cout<<i<<" ";
        cout<<endl;
        
        vec.clear();
        inorderTraversal_iteratively(root, vec);
        cout<<"iteratively:"<<endl;
        for (int i : vec) cout<<i<<" ";
        cout<<endl;
        
        return vec;
    }
    
    void inorderTraversal_iteratively(TreeNode* root, vector<int>& vec) {
        TreeNode* tmp = root;
        stack<TreeNode*> st;
        while (tmp) {
            if (tmp->left) {
                st.push(tmp);
                tmp = tmp->left;
            }
            else if (tmp->right) {
                vec.push_back(tmp->val);
                tmp = tmp->right;
            }
            else {
                vec.push_back(tmp->val);
                while (1) {
                    if (st.empty()) return;
                    tmp = st.top();
                    st.pop();
                    vec.push_back(tmp->val);
                    if (tmp->right) {
                        tmp = tmp->right;
                        break;
                    }
                }
            }
        }
    }
    
    void inorderTraversal_recursively(TreeNode* root, vector<int>& vec) {
        if (root) {
            inorderTraversal_recursively(root->left, vec);
            vec.push_back(root->val);
            inorderTraversal_recursively(root->right, vec);
        }
    }
};

// []
// [1]
// [1,2]
// [1,null,2]
// [1,2,3,4,5,6,7]
// [1,2,null,3,4]
// [1,null,2,3]
// [1,2,null,3,8,4,null,null,null,5,6]

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        prettyPrintTree(root);
        
        Solution solution;
        solution.inorderTraversal(root);
    }
    return 0;
}