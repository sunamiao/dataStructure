#include <iostream>
#include <vector>
#include "stackl.h"
#include <ctime>
using namespace std;
void testlongestValidParentheses() {

    //*********************//
    vector<pair<string, int>> testCases = {
        {"(()", 2},           // 测试例子 1
        {")()())", 4},        // 测试例子 2
        {"((()))", 6},        // 测试例子 3
        {"", 0},              // 测试例子 4
        {"(((", 0},           // 测试例子 5
        {")))", 0},           // 测试例子 6
        {"()(()", 2},         // 测试例子 7
        {")(()))()(())", 6},  // 测试例子 8
        {"()()()()", 8},      // 测试例子 9
        {"((()()))", 8}       // 测试例子 10
    };
    int passed = 0;
    int total = testCases.size();

    for (int i = 0; i < total; i++) {
        string s = testCases[i].first;
        int expected = testCases[i].second;
        int result = longestValidParentheses(s);

        cout << "Test " << (i + 1) << ": \"" << s << "\"" << endl;
        cout << " -> Expected: " << expected << ", Got: " << result << endl;

        if (result == expected) {
            cout << "PASSED" << endl;
            passed++;
        } else {
            cout << "FAILED" << endl;
        }
    }

    // 输出测试结果统计

    cout << "\n=== Test Summary ===" << endl;
    cout << "Passed: " << passed << "/" << total << endl;
    cout << "Success rate: " << (passed * 100.0 / total) << "%" << endl;
}
int main() {

    clock_t start = clock();

    //*********************//




    //*********************//

    clock_t end = clock();
    double cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "CPU time used: " << cpu_time_used << " s\n";


    std::cout << "Current timestamp: " << time(0) << endl;
    return 0;
}
