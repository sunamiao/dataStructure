//
// Created by andong on 2025/10/8.
//

#include "hash.h"
#include <unordered_map>

//1.两数之和 hash table
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> t;
    for(int i=0; i<nums.size();i++) {
        auto it = t.find(target-nums[i]);
        if(it!=t.end()) {
            return {i,it->second};
        }
        t[nums[i]] =i;
    }
    return {};
}