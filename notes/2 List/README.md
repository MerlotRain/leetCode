# 链表

* 链表
* 双向链表
* 双向循环链表


## 链表

### 应用场景

* [redis slowlog](Redis%20slowlog.md)


### 链表 VS 数组

特点

* 数组 : 内存连续, 更好利用局部性原理；内存空间必须一次性分配够，所以说数组如果要扩容，需要重新分配一块更大的空间，再把数据全部复制过去,有界
* 链表 : 不存在数组的扩容问题, 空间不连续，你无法根据一个索引算出对应元素的地址，所以不能随机访问； 需要前后元素位置的指针，会消耗相对更多的储存空间

优缺点：

* 查询： 数组 O(1), 有序时可以用二分查找；
* 删除： 链表只需要移动指针 O(1) ，数组的话删除元素需要移动后续的元素 O(N)




### 扩缩容

简单说下编程语言 java， golang中 LinkList的扩缩容的策略。

java 中扩容，每次扩容新增原先容量的 1/2
```
 int newCapacity = oldCapacity + (oldCapacity >> 1);
```

这个就不介绍了。重点说下双向链表。



## 双向链表

双向链表也叫双链表，是链表的一种，它的每个数据结点中都有两个指针，分别指向直接后继和直接前驱。所以，从双向链表中的任意一个结点开始，都可以很方便地访问它的前驱结点和后继结点。一般我们都构造双向循环链表。

双向链表克服了单链表中访问某个节点前驱节点(插入，删除操作时)，只能从头遍历的问题。

缺点是： 多了1倍的额外的指针空间大小。

```
typedef int Value
typedef struct Entry{
	struct Entry *next,*prev;
	Value value;
}DoubleLink;

```

应用场景

* mysql B+树 叶子节点就使用 双向链表，方便 `age<10` 类似条件查询，或者 倒序查询 如 `order by desc` ，从后向前遍历数据
* Java  AQS 中的等待队列， 是一个双端 双向链表 的结构 （FIFO 结构）


## 循环链表

最后一个节点指针指向头节点的链表

[QPS 计数器实现](QPS%20Counter.md)


## 双向循环链表











