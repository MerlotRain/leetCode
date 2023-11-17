#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Node {
  int value;
  int in;
  int out;
  std::vector<Node *> nexts;
  std::vector<Edge *> edges;
  Node() {
    value = 0;
    in = 0;
    out = 0;
  }
  Node(int val) {
    value = val;
    in = 0;
    out = 0;
  }
};

struct Edge {
  int weight;
  Node *from;
  Node *to;

  Edge() {
    weight = 0;
    from = NULL;
    to = NULL;
  }
  Edge(int w, Node *f, Node *t) : weight(w), from(f), to(t) {}
  bool operator<(const Edge &rhs) const { return weight < rhs.weight; }
};

struct Graph {
  std::unordered_map<int, Node *> nodes;
  std::unordered_set<Edge *> edges;
};

Graph *createGraph(std::vector<std::vector<int>> table) {
  Graph *graph = new Graph();
  for (int i = 0; i < table.size(); i++) {
    int from = table[i][0];
    int to = table[i][1];
    int weight = table[i][2];
    if (graph->nodes.find(from) == graph->nodes.end()) {
      graph->nodes.insert({from, new Node(from)});
    }
    if (graph->nodes.find(to) == graph->nodes.end()) {
      graph->nodes.insert({to, new Node(to)});
    }

    Node *fromNode = graph->nodes[from];
    Node *toNode = graph->nodes[to];
    Edge *edge = new Edge(weight, fromNode, toNode);
    fromNode->nexts.push_back(toNode);
    fromNode->out++;
    toNode->in++;
    fromNode->edges.push_back(edge);
    graph->edges.insert(edge);
  }
  return graph;
}

/// @brief 邻接矩阵生成图模型
/// @param matrix
/// @return
Graph *createGraph2(std::vector<std::vector<int>> matrix, int n) {
  Graph *graph = new Graph();
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      
    }
  }
}

/**
 * @brief graph algorithm
 *
 */

/**
 * @brief 图的宽度优先遍历
 *
 * @param node
 */
void graphBFS(Node *node) {
  if (node == NULL)
    return;

  std::queue<Node *> que;
  // set决定了图一定可以遍历完成
  std::unordered_set<Node *> set;
  que.push(node);
  set.insert(node);

  while (!que.empty()) {
    Node *cur = que.front();
    que.pop();
    std::cout << cur->value;
    for (auto &next : cur->nexts) {
      if (set.find(next) == set.end()) {
        que.push(next);
        set.insert(next);
      }
    }
  }
}

/**
 * @brief 图的深度优先遍历
 *
 * @param node
 */
void graphDFS(Node *node) {
  if (!node)
    return;

  std::stack<Node *> stk;
  std::unordered_set<Node *> set;
  stk.push(node);
  set.insert(node);

  while (!stk.empty()) {
    Node *cur = stk.top();
    stk.pop();
    for (auto &next : cur->nexts) {
      if (set.find(next) == set.end()) {
        stk.push(cur);
        stk.push(next);
        set.insert(next);
        // std::cout << next->value;
        break;
      }
    }
  }
}

/**
 * @brief 拓扑排序算法
 *
 * @param graph
 * @return std::vector<Node *>
 */
std::vector<Node *> topo(Graph *graph) {
  // key 一个节点
  // value 剩余的入度
  std::unordered_map<Node *, int> inMap;
  // 入度为0 的点
  std::queue<Node *> zeroInQue;

  for (auto it = graph->nodes.begin(); it != graph->nodes.end(); ++it) {
    inMap.insert({it->second, it->second->in});
    if (it->second->in == 0) {
      zeroInQue.push(it->second);
    }
  }

  std::vector<Node *> result;
  while (!zeroInQue.empty()) {
    Node *cur = zeroInQue.front();
    zeroInQue.pop();
    result.push_back(cur);

    for (auto &next : cur->nexts) {
      inMap.insert({next, inMap[next] - 1});
      if (inMap[next] == 0) {
        zeroInQue.push(next);
      }
    }
  }
  return result;
}

/// 无向图的P,K算法

struct UnionSet {
  std::unordered_map<Node *, std::list<Node *>> setmap;

  UnionSet(std::list<Node *> nodes) {
    for (auto &cur : nodes) {
      std::list<Node *> set;
      set.push_back(cur);
      setmap.insert({cur, set});
    }
  }

  bool sameSet(Node *from, Node *to) {
    auto it1 = setmap.find(from)->second;
    auto it2 = setmap.find(to)->second;
    return it1 == it2;
  }
};

void primMST(Graph *graph) {

  std::priority_queue<Edge *> proEdges;
  std::set<Node *> sn;
  std::set<Edge *> result;

  for (auto it = graph->nodes.begin(); it != graph->nodes.end(); ++it) {
    if (sn.find(it->second) == sn.end()) {
      sn.insert(it->second);

      for (auto &edge : it->second->edges) {
        proEdges.push(edge);
      }

      while (!proEdges.empty()) {
        Edge *edge = proEdges.top();
        Node *toNode = edge->to;
        if (sn.find(toNode) == sn.end()) {
          sn.insert(toNode);
          result.insert(edge);
        }
        for (auto &nextEdge : toNode->edges) {
          proEdges.push(nextEdge);
        }
      }
    }
  }
}

/**
 * @brief 规定一个出发点，获取从这个点到其他点的算法
 * @details 可以有权值为负数的边，但不能有负数的环
 *
 * @return Node*
 */
Node *minDistanceAndUnSelectedNode(std::unordered_map<Node *, int>,
                                   std::unordered_set<Node *>);

/**
 * @brief
 *      B
 *     /
 *   10
 *  /
 * A----------3----------D
 *  \
 *   3
 *   \
 *    C
 *
 * @param head
 * @return * std::unordered_map<Node *, int>
 */
std::unordered_map<Node *, int> dijkstra(Node *head) {
  /// 从head出发到所有点的距离
  /// key: 从head出发到达的key
  /// value: 从head出发的最小距离
  /// 如果没有找到，则认为距离无穷大
  std::unordered_map<Node *, int> distance;
  distance.insert({head, 0});
  std::unordered_set<Node *> selectedNodes;

  Node *min = minDistanceAndUnSelectedNode(distance, selectedNodes);
  while (!min) {
    int dis = distance[min];
    for (auto edge : min->edges) {
      Node *toNode = edge->to;
      if (distance.find(toNode) == distance.end()) {
        distance.insert({toNode, (edge->weight + dis)});
      }
      distance.insert(
          {edge->to, std::min(distance[toNode], edge->weight + dis)});
    }
    selectedNodes.insert(min);
    min = minDistanceAndUnSelectedNode(distance, selectedNodes);
  }
  return distance;
}

Node *minDistanceAndUnSelectedNode(std::unordered_map<Node *, int> distance,
                                   std::unordered_set<Node *> touchedNodes) {
  Node *minNode = NULL;
  int minDistance = INT_MAX;
  for (auto it = distance.begin(); it != distance.end(); ++it) {
    Node *node = it->first;
    int dis = it->second;
    if (touchedNodes.find(node) == touchedNodes.end() && dis < minDistance) {
      minNode = node;
      minDistance = dis;
    }
  }
  return minNode;
}