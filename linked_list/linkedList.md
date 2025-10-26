### 线性表——链式描述

#### **概述**
链表中，线性表的元素在内存中的存储位置是随机的。
- 链式描述
- 链表，循环表，双向链表
- 头节点

STL的容器类`list`使用带有头节点的双向循环链表来描述实例。与`vector`方法类似。

#### 单向链表
##### 描述
线性表每一个元素用节点来描述，**节点**可以不是数组成员。节点明确包含另一个相关节点的位置信息，这个信息称为**链(link)**或**指针(pointer)**。
![img.png](img.png)
#### 结构chainNode
```c++
template <class T>
struct chainNode
{
//  数据成员
T element;
chainNode<T> *next;

// 方法
chainNode() {}
chainNode(const T& element) {this->element = element;}
chainNode(const T& element, chainNode<T>* next) {
    this->element  = element;
    this->next = next; 
}
```
#### 类chain
1. 链表 chain 的方法 header, empty 和 size

类 chain 用单向链表实现了线性表,最后一个节点的指针域为NULL，即它用单向链表的一组节点实现了线性表。
```c++
template<class T>
class chain:public linerLiat<T>
{
    public:
    // 构造函数，复制构造函数和析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    ~chain();
    
    //抽象数据类型ADT的方法
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    protected:
    void checkIndex(int theIndex) const;
    // 如果索引无效，抛出异常
    chainNode<T>* firstNode; //指向链表第一个节点的指针
    int listSize; //线性表的元素个数
    
};
```

2. 构造函数和复制构造函数

为了创造一个空链表，只需令第一个节点指针`firstNode`的值为**NULL**。与数组描述的线性表不同，链表在创建时不需要估计元素的最大个数以分配初始空间。

```c++
// 6-3 链表的构造函数和复制构造函数
template<class T>
chain<T>::chain(int initialCapacity)
{//构造函数

    
}
```

3. 析构函数

析构函数要逐个清除链表的节点，重复清楚链表的首元素节点，直到链表为空。
```c++
template<class T>
chain<T>::~chain(){
    while(firstNode != NULL){
    //删除首个节点
    chainNode<T> *nextNode = firstNode -> next;
    delete firstNode;
    firstNode = nextNode;
    }
}
```

4. 方法 `get`
在链表中，要寻找索引为`theIndex`的元素，必须从第一个节点开始，跟踪链域`next`直至找到所需的元素集结点指针，
也就是说必须跟踪theIndex个指针，时间复杂度为*O(theIndex)*
```c++
//方法get的返回值是索引为theIndex的元素
template<class T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for(int i=0; i<theIndex;i++){
    currentNode = currentNode->next;
    return currentNode->element;
}
```
5. 方法`indexOf`
用当前节点的指针确定下一个相邻节点的位置
```c++
// 返回元素theElement首次出现时的索引
template<class T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0; //当前节点的索引
    while( currentNode != NULL and currentNode->element != theElement){ 
        current = current->next;
        index++;
    }
    if(currentNode == NULL){
        return -1;}
    else return idex;
    
}
```
6. 方法 `erase`

删除索引为`theIndex`的元素

- theIndex<0 或者 theIndex>=listSize.
- 删除非空表的第0个元素节点
- 删除其他元素节点

```c++
template<class T>
void chain<T>::erase(int theIndex){
    // 删除索引为theIndex的元素
    // 若元素不存在，则抛出异常
    checkIndex(theIndex);
    
    // 索引有效，需找到要删除的元素节点
    chainNode<T>* deleteNode;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        //用指针p指向要删除节点的前驱节点
        chainNode<T>* p = firstNode;
        for(int i=0; i < theIndex -1 ; i++){
            p = p->next;
        } 
        deleteNode = p->next;
        p->next = p->next->next; // 删除deleteNode 指向的节点 
    }
    listSoze--;
    delete deleteNode;
}
```
7 方法 `insert`

