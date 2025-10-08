//
// Created by andong on 2025/10/4.
//
/*
 *五个中等
 *四个简单
 *一个困难
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <string>
using namespace std;
// 1. 两数之和
std::vector<int> twoSum(std::vector<int>& nums, int target);

// 4. 寻找两个正序数组的中位数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

// 11. 盛最多水的容器。
int maxArea(vector<int>& height);

// 14.最长公共前缀
string longestCommonPrefix(vector<string>& strs);
// 15,三数之和
vector<vector<int>> threeSum(vector<int>& nums);
// 16.最接近的三数之和
int threeSumClosest(vector<int>& nums, int target);
// 18. 四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target);

//26. 删除有序数组中的重复项
int removeDuplicates(vector<int>& nums);

//27.移除元素
int removeElement(vector<int>& nums, int val);

//31. 下一个排列
void nextPermutation(vector<int>& nums);
//33. 搜索旋转排序数组
int search(vector<int>& nums, int target);
//
#endif //ARRAY_H
