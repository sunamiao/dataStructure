//
// Created by andong on 2025/10/19.
//
#include <iostream>
#include "linkedList.h"
#include <algorithm>
#include <unordered_map>
using namespace std;
//1.两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> t;
    for(int i=0; i<nums.size(); i++) {
        auto it = t.find(target- nums[i]);
        if(it != t.end()) {
            cout << it->first << endl;
            return {i, it->second};

        }
        t[nums[i]] = i;
        // 调试输出：打印当前哈希表状态
        cout << "Current hash table: ";
        for(const auto& pair : t) {
            cout << "{" << pair.first << ":" << pair.second << "} ";
        }
        cout << endl;
    }
    return {};
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for(int i=0; i<nums2.size();i++) {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(),nums1.end());
    int l = nums1.size();
    if(nums1.size() % 2==0) {
        return (nums1[l/2] + nums1[l/2 -1])/2.0;
    }return nums1[(l+1)/2 -1];
}

// 2.两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode* dummyNode = new ListNode(0);
    ListNode* current = dummyNode;

    while(l1 != nullptr || l2 != nullptr || carry != 0) {
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l2 != nullptr) ? l2->val : 0;

        int sum = carry + val1 + val2;

        carry = sum / 10;
        int digit = sum % 10;

        current->next = new ListNode(digit);
        current = current->next;

        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;
    }
    return dummyNode->next;

}

// 44.通配符匹配
bool isMatch(string s, string p) {

}