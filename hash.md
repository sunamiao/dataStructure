### 滑动窗口
```c++
// 外层循环扩展右边界，内层循环扩展左边界
/*
for(int l = 0, r = 0; r < n ; r++) {
  // 当前考虑的元素
  while (l<= r && check()) {
           // 扩展左边界
  }
  // 区间 [left, right] 符合题意， 统计相关信息
}

 */
int lengthOfLongestSubstring(string s) {
    // 滑动窗口
    unordered_set<char> occ;
    int rk = -1, ans = 0; // 右指针初始为-1表示没开始移动
    for(int i=0; i<s.length(); i++) {
        if (i != 0) occ.erase(s[i-1]);
        while (rk+1 < s.length() && !occ.count(s[rk+1])) {
            //occ.count(s[rk + 1]) 检查这个字符是否已经在集合中存在
            occ.insert(s[rk+1]);
            std::cout << occ << std::endl;
            rk++;
        }
        ans = max(ans, rk-i+1);
    }
    return ans;
}
```