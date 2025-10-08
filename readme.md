## 数组

1.双指针

2.二分法

## 哈希表
`哈希表(Hash Table)`是一种使用`哈希函数`组织数据，以支持**快速插入**和**搜索**的数据结构。
有两种不同类型的哈希表：哈希集合和哈希映射。
- `哈希集合`是`集合`的实现方式之一，用于存储`非重复值`。
- `哈希映射(unordered_map)`是`映射`的实现方式之一，用于存储`(key,value)`键值对。

### 为什么要用哈希函数
如果直接在数组中查找某个 *key*（比如字符串`"banana"`)，那要`O(n)`的时间。

如果通过哈希函数：`index = h("banana");`。就能直接跳到数组的对应位置去查找或插入，只要O(1)时间，非常快。

`HashTable<Key, Value>`包含：
- `insert(key, value)`插入键值对
- get(key)获取值
- remove(key)删除键

### 哈希表的核心思想
1.用一个数组存储若干桶（bucket);

2.每个桶里是一个`std::list<pair<key,Value>>`;

3.通过哈希函数`hash(key)`决定`key`属于哪个桶

4，查找时只需访问一个桶。

### 完整代码
```c++
// HashTable.h
#ifndef HSHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
#include <functional> // for std::hash
using namespace std;

template<typename Key, typename Value>
class HastTable {
private:
    static const int DEFAULT_BUCKETS = 10; // 默认桶数量
    vector<list<pair<Key, Value>>> table; // 每个桶是一个链表
    int numElements; // 当前元素个数
    
    // 哈希函数： 用std:hash
    int getBucketIndex(const Key& key) const {
        return hash<Key>{}(key) % table.size();
    }

public:
    HashTable(int bucketCount = DEFAULT_BUCKETS) : table(bucketCount), numElements(0) {}
    //
};

#endif // HASHTBLE_H
```

