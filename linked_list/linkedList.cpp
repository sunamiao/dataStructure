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
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    //初始化，空模式匹配空字符串
    dp[0][0]=true;

    //处理模式串以'*'开始的情况
    for(int  j = 1; j<= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i<=m;i++) {
        for(int j = 1; j<=n; j++) {
            if(p[j-1] == '*') {
                // '*'可以匹配空字符或一个或多个字符
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }else if (p[j-1] == '?' || p[j-1]==s[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            }else {
                dp[i][j] = false;
            }
        }
    }



    return dp[m][n];//返回最右下角位置的bool值
}