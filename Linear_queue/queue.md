## 队列

### 引入
队列(queue)是一种具有 *先进先出* 性质的表，first in first out(FIFO) 表。

![队列动画示意图](queue.svg)

### 数组模拟队列

通常用一个数组模拟一个队列，用两个变量标记队列的首尾。`int q[SIZE], ql = 1, qr;`

队列操作对应的代码如下：
- 插入元素： `q[++qr] = x;`
- 删除元素： `ql++;`
- 访问队首： `q[ql];`
- 访问队尾： `q[qr];`
- 清空队列： `ql = 1; qr = 0;`

```c++
#include <cstdio>
using namespace std;

const int SIZE = 10000 + 5;

struct Queue {
    int q[SIZE], ql, qr;
    Queue():ql(1),qr(0) {}
    bool empty() {return ql > qr;}
    void push(int x) { q[++qr] = x; }
    void pop() {++ql;}
    int front() {return q[ql]; }
    int back() {return q[qr];  }
    int size() { return qr - ql + 1;}
    int clear() {
            ql = 1;
            qr = 0;
            }
 };
    
int main(){
    Queue q;
    int n;
    scanf("%d", &n);
    while (n--) {
        int opt;
        scanf("%d", &opt);
        if(opt == 1){
            int x;
            scanf("%d", &x);
            q.push(x);
        }else if(opt = 2){
            if(q.empty())
            printf("ERR_CANNOT_POP\n");
            else
                q.pop();
        }else if(opt = 3){
        
            if(q.empty())
            printf("ERR_CANNOT_QUERY\n");
            else
            printf("%d\n", q.friont());
        } else
            printf("%d\n", q.size())
    
    }
    return 0;
}
```
