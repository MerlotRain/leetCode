# 图

### 什么是图

图论（Graph theory）是数学的一个分支，它以图为研究对象，研究顶点和边组成的图形的数学理论和方法。图论中的图是由若干给定的顶点及连接两顶点的边所构成的图形，这种图形通常用来描述某些事物之间的某种特定关系，用顶点代表事物，用连接两顶点的边表示相应两个事物间具有这种关系。

图论的研究对象相当于一维的拓扑学。


### 应用场景

工业界有哪些应用场景?

* 匹配，如打车中司乘匹配引擎，如何做到效率最优
* 并行任务调度： 一组任务，任务有优先级，如何合理安排任务调度，在最短时间内完成
* 导航路径规划:在使用导航软件时,用户在选择一个开始地点和目的地之后导航软件会给出各种如路程最短，不走高速，时长最短等方案
* 社区发现: 在好友关系中，根据社区之间联系或紧密，利用图 louvain 算法或者其他算法对用户进行分群从而达到精准营销，个性化服务等
* 金融贷后催收：利用图算法找出符合条件的失联人的联系人，从而提高催收失联修复的覆盖率、有效联系率，助力不良资产的回收
* 套汇 


### 基本概念

** 有向图 **

有向图，就是有方向的图

** 无向图 **

就是没有方向的图

** 环 **

首尾相接的路径我们就把它叫做一个环。


# 图的存储结构

* 对象和指针
* 邻接矩阵 （二维数组）
* 邻接表


图数据结构表示：

```

```


## 图的操作

#### 遍历

* 广度优先 BFS
* 深度优先 DFS

Dijkstra
A*

用于游戏编程和分布式计算


## 图延伸

* 二部图
* 有向无环图 DAG


### 参考

https://www.jiqizhixin.com/articles/2019-05-16-14







