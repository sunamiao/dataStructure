//
// Created by andong on 2025/10/19.
//
/*链表LinkedList是最简单的线性的，动态数据据结构。
 *链表在插入数据的时候可以达到O(1)的复杂度，但是查找一个节点或者访问特定编号的节点则需要O(n)的时间
 *链表增加了节点的指针域，空间开销比较大。
 */

#include <iostream>
#include "linkedList.h"
using namespace std;
int main() {
  vector<int> nums = {2,7,11,15};
    int target = 17;
    vector<int> result = twoSum(nums,target);
    cout << "llMain" << endl;

}