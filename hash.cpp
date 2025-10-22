//
// Created by andong on 2025/10/8.
//

#include "hash.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>

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
// 3.无重复字符的最长字串
int lengthOfLongestSubstring(string s) {
    // 滑动窗口 peeked
    unordered_set<char> occ;
    int rk = -1, ans = 0;
    for(int i=0; i<s.length(); i++) {
        if (i != 0) {
            occ.erase(s[i-1]);
            cout << "Remove character by left pointer: '" << s[i-1] << "'" << endl;
        };
        while (rk+1<s.length() && !occ.count(s[rk+1])) {
            occ.insert(s[rk+1]);
            cout << "Add character by right pointer: '" << s[rk + 1] << "'" << endl;
            rk++;
        }
        int currentLength = rk - i + 1;
        ans = max(ans, currentLength);
        for(auto c:occ) {
            cout << c;
        }
        cout << endl;
        cout << "Window: [" << i << "," << rk << "] Length: " << currentLength << endl;
    }

    return ans;
}