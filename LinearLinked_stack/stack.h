//
// Created by 19642 on 2025/10/23.
//

#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
using namespace std;
// 20.有效的括号
bool isValid(string s);

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
// 94. 二叉树的中序遍历
vector<int> inorderTraversal(TreeNode* root);
// 144. 二叉树前序遍历
vector<int> preorderTraversal(TreeNode* root);

// 234.回文链表
// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode* head);

#endif //STACK_H
