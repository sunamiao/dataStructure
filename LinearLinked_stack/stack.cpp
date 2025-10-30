//
// Created by 19642 on 2025/10/23.
//
#include "stack.h"

#include <stack>
// 20.有效的括号
bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(st.empty()) {return false;}

            if (st.top() == '(' && s[i] == ')') {
                st.pop();
            }else if (st.top() == '{' && s[i] == '}') {
                st.pop();
            }else if (st.top() == '[' && s[i] == ']') {
                st.pop();
            }else return false;
        }
    }
    return st.empty();
}

// 94. 二叉树的中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    // 左子树->根节点->右子树
    int WHITE = 0, GRAY = 1;
    vector<int> res;
    stack<pair<TreeNode*, bool>> stack;
    pair<TreeNode*, bool> p = make_pair(root, false);
    stack.push(p);
    while (!stack.empty()) {
        bool color = stack.top().second;
        TreeNode* node = stack.top().first;
        stack.pop();

        if (node == nullptr) continue;  // 添加空节点检查
        if (color==WHITE) {
            stack.push(make_pair(node->right,WHITE));
            stack.push(make_pair(node,GRAY));
            stack.push(make_pair(node->left,WHITE));
        }else {
            res.push_back(node->val);
        }
    }
    return res;
}

// 144. 二叉树前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    int WHITE = 0, GRAY = 1;
    vector<int> res;
    stack<pair<TreeNode*, bool>> stack;
    pair<TreeNode*, bool> p = make_pair(root, false);    //root 是指向节点 1 的指针
    stack.push(p);
    while (!stack.empty()) {
        bool color = stack.top().second;
        TreeNode* node = stack.top().first;
        stack.pop();
        if (node==nullptr) continue;
        if (color==WHITE) {
            stack.push(make_pair(node->right,WHITE));
            stack.push(make_pair(node->left,WHITE));
            stack.push(make_pair(node,GRAY));
        }
        else {
            res.push_back(node->val);
        }
    }
    return res;
}

//145. 二叉树后序遍历

vector<int> postorderTraversal(TreeNode* root) {
    int WHITE = 0, GRAY = 1;
    vector<int> res;
    stack<pair<TreeNode*, bool>> stack;
    pair<TreeNode*, bool> p = make_pair(root, false);
    stack.push(p);
    while (!stack.empty()) {
        bool color = stack.top().second;
        TreeNode* node = stack.top().first;
        stack.pop();
        if (node==nullptr) continue;
        if (color==WHITE) {
            stack.push(make_pair(node,GRAY));
            stack.push(make_pair(node->right,WHITE));
            stack.push(make_pair(node->left,WHITE));
        }
        else {
            res.push_back(node->val);
        }
    }
    return res;
}

// 234.回文链表
bool isPalindrome(ListNode* head) {

}