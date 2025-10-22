//
// Created by 19642 on 2025/10/22.
//

#include "stackl.h"

#include <sstream>
#include <stack>

bool isValid(string s) {
    stack<char> stack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.empty()) {return false;}

            else if (stack.top() == '(' && s[i] == ')') {
                stack.pop();
            }
            else if (stack.top() == '{' && s[i] == '}') {
                stack.pop();
            }
            else if (stack.top() == '[' && s[i] == ']') {
                stack.pop();
            }else return false;
        }
    }
    return stack.empty();
}

int longestValidParentheses(string s) {
    int result = 0;
    stack<int> stack;
    stack.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(i);
        }else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            }else {
                result = max(result, i - stack.top());
            }
        }
    }
    return result;
}

// 42.接雨水
int trap(vector<int>& height) {
    int ans = 0;
    stack<int> stack;
    int n = height.size();
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && height[i] > height[stack.top()]) {
            int top = stack.top();
            stack.pop();
            if (stack.empty()) {
                break;
            }
            int left = stack.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        stack.push(i);
    }
    return ans;
}

// 4.简化路径
string simplifyPath(string path) {
    vector<string> stack;
    istringstream ss(path);  // 将字符串转为输入流
    string s;
    while (getline(ss, s, '/')) {
        if (s.empty() || s == ".") {
            continue;
        }
        if (s != "..") {
            stack.push_back(s);
        } else if (!stack.empty()) {
            stack.pop_back();
        }
    }
    string ans;
    for (string& s : stack) {
        ans += '/';
        ans += s;
    }
    return stack.empty() ? "/":ans;
}