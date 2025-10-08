//
// Created by andong on 2025/10/4.
//

#include "array.h"
#include <unordered_map>
#include <iostream>
#include "algorithm"
using namespace std;

// 1. 两数之和
std::vector<int> twoSum(std::vector<int> &nums, int target) {
    //哈希表
    unordered_map<int, int> t; //<值，下标>

    for(int i=0;  i < nums.size(); i++) {
        auto it = t.find(target - nums[i]);
        if(it != t.end()) {
            return {it->second, i};
        }
        t[nums[i]] = i;
    }
    return {};
}

// 4. 寻找两个正序数组的中位数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for(int i=0; i<nums2.size();i++) {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(),nums1.end());
    double sum = 0;
    int l = nums1.size();
    cout << l << endl;
    if(l%2==0) sum = (nums1[l/2] + nums1[(l/2 - 1)])/2.0;
    else sum = nums1[(l+1)/2 -1];
    return sum;
}

// 11. 盛最多水的容器。
/*
int maxArea(vector<int>& height) {
    int Currentmax = 0;
    for(int i = 0;i<height.size();i++) {
        for(int j = i+1; j < height.size(); j++) {
            int temp = (j-i) * min(height[i], height[j]);
            //cout << "temp = " << temp << endl;
            Currentmax = max(temp,Currentmax);
        }
    }
    return Currentmax;
}
// Runtime out CPU time used: 16.334 s 705634720
*/
// 双指针
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        // 计算当前面积
        int currentArea = (right - left) * min(height[left], height[right]);
        maxArea = max(maxArea, currentArea);

        // 移动高度较小的指针
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

// 14.最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
    string& longPrefix = strs[0]; // flower
    for(int i=0; i< strs[0].size(); i++) { // 对列比较
        cout << longPrefix[i] << ",";
        for(auto& s:strs) { // 对行
            if(s[i]!=longPrefix[i] or i==longPrefix.size()) {
                return longPrefix.substr(0,i);
            }
        }
    }

    return longPrefix;

}

// 15,三数之和
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> result = {};
    if(nums.size() < 3) return {};

    for(int i=0; i<nums.size()-2;i++) {
        int left = i+1, right = nums.size()-1;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == 0) {
                result.push_back({nums[left],nums[i],nums[right]});
                // 跳过重复的left和right
               //while (left < right && nums[left] == nums[left + 1]) left++;
                //while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }else if (sum > 0) {
                right--;
            }

        }
    }
    return result;
}

// 16, 最接近的三数之和
int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(),nums.end());
    if(nums.size() < 3) return {};
    int closestSum=nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size()-2; i++) {
        int left = i+1, right = nums.size()-1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(abs(sum-target) < abs(closestSum-target)) {
                closestSum=sum;
            }
            if(sum < target)left++;
            else if(sum > target)right--;
            else return sum;

        }
    }
    return closestSum;
}

// 18.四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {};
    if(nums.size() < 4)  return {};

    for(int j=0; j<nums.size()-3;j++) {
        if (j > 0 && nums[j] == nums[j - 1]) continue;
        for(int i=j+1; i<nums.size()-2;i++) {
            int left = i+1, right = nums.size()-1;
            if (i > j+1 && nums[i] == nums[i - 1]) continue;
            while(left<right) {
                int sum = nums[j] + nums[i] + nums[left] + nums[right];
                //long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    result.push_back({nums[i], nums[j],nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum < target) {
                    left++;
                }else if(sum > target) {
                    right--;
                }
            }
        }
    }

    return result;
}

// 26. 删除有序数组中的重复项
int removeDuplicates(vector<int>& nums) {
  //  sort(nums.begin(), nums.end());
    int i = 0;
    while(i<nums.size()-1) {
        if(nums[i]==nums[i+1]  )  {
            nums.erase(nums.begin() + i);
        }else {
            i++;
        }
    }
    return nums.size();
}
//27. 移除元素
int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(),nums.end());
    int slow = 0;
    for(int fast=0;fast<nums.size();fast++) {
        if(nums[fast] !=val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

//31. 下一个排列
void nextPermutation(vector<int>& nums) {
    cout << "";
}

//33.搜索旋转排序数组
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while(left<right) {
        int mid = left + (right-left)/2;
        if(nums[mid]==target) return mid;

        if(nums[left] >= nums[mid]) { //左边有序
            if(nums[left]<=target && target < nums[mid]) {
                // 在mid的左边
                right = mid-1;
            }else {
                left = mid+1;
            }
        }else if(nums[left] <= nums[mid]) {  //右边有序
            if(nums[mid] < target && target <= nums[right]) {
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
    }

    return -1; // 未找到
}



