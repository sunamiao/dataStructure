//
// Created by 19642 on 2025/10/28.
//
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    string s = "()[]{}";
    bool result = isValid(s);
    cout << (result?"true":"false")<< endl;
    cout << "stack: Last in First Out" << endl;
    return 0;
}