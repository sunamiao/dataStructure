//
// Created by andong on 2025/10/19.
//
#include <vector>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);

// 4. 寻找两个正序数组的中位数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums);

// 链表 linkedList
// 2.两数相加
//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

// 19.删除链表的倒数第N个结点

// 44.通配符匹配
bool isMatch(string s, string p);
#endif //LINKEDLIST_H
