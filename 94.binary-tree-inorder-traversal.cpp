/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (74.95%)
 * Likes:    12586
 * Dislikes: 674
 * Total Accepted:    2.2M
 * Total Submissions: 3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  /**
   * 二叉树遍历的问题
   *
   * 我们对一个二叉树，肯定要递归左、右节点
   * 所以形成了三个位置
   * 先（头、左、右）
   * 中（左、头、右）
   * 后（左、右、头）
   *
   * 我们每次打印的时候都是打印头节点，所以头在哪里，就在哪里打印
   */
  void preOrderRecur(TreeNode *head, vector<int> &res) {
    if (head == NULL)
      return;

    res.push_back(head->val);
    preOrderRecur(head->left, res);
    preOrderRecur(head->right, res);
  }

  void posOrderRecur(TreeNode *head, vector<int> &res) {
    if (head == NULL)
      return;

    posOrderRecur(head->left, res);
    posOrderRecur(head->right, res);
    res.push_back(head->val);
  }

  void inorderRecur(TreeNode *head, vector<int> &res) {
    if (head == NULL)
      return;

    inorderRecur(head->left, res);
    res.push_back(head->val);
    inorderRecur(head->right, res);
  }

  // 非递归先序遍历
  /**
   * 先把头节点压到栈中。
   * 1、先弹出一个节点，操作（打印）
   * 2、再压入这个节点的右、左（如果有）
   * 3、重复第一步。
   */
  std::vector<int> preOrderUnRecur(TreeNode *head) {
    std::vector<int> res;
    if (head == NULL)
      return res;
    stack<TreeNode *> stk;
    stk.push(head);
    while (!stk.empty()) {
      head = stk.top();
      stk.pop();
      res.push_back(head->val);

      if (head->right != 0)
        stk.push(head->right);
      if (head->left != 0)
        stk.push(head->right);
    }
    return res;
  }

  /**
   * @brief 非递归后序遍历
   * 1、先弹出
   * 2、弹出的压入另一个栈
   * 3、压入左、右
   * @param head
   * @return std::vector<int>
   */
  std::vector<int> posOrderUnRecur(TreeNode *head) {
    std::vector<int> res;
    if (head != NULL) {
      stack<TreeNode *> stk1;
      stack<TreeNode *> stk2;

      stk1.push(head);
      while (!stk1.empty()) {
        head = stk1.top();
        stk1.pop();
        stk2.push(head);
        if (head->left != NULL)
          stk1.push(head->left);
        if (head->right != NULL)
          stk1.push(head->right);
      }

      while (!stk2.empty()) {
        res.push_back(stk2.top()->val);
        stk2.pop();
      }
    }
    return res;
  }

  /**
   * @brief
   *
   * @param node
   * @return std::vector<int>
   */
  std::vector<int> inOrderUnRect(TreeNode *head) {
    std::vector<int> res;
    if (head != NULL) {
      std::stack<TreeNode *> stk;
      while (!stk.empty() || head != NULL) {
        // 不断查找head的左节点
        if (head != NULL) {
          stk.push(head);
          head = head->left;
        } else {
          // 左边没有了，弹出一个
          head = stk.top();
          stk.pop();
          res.push_back(head->val);
          head = head->right;
        }
      }
    }
    return res;
  }

/**
 *              1
 *            /  \
 *           2   3
 *         / \  / \
 *        4  5 6  7
 * 
 * queue
 * 1 => 1
 * 2,3 => 2
 * 3,4,5 => 3
 * 4,5,6,7 => 4
 * 5,6,7 => 5
 * 6,7 => 6
 * 7 => 7
 * end
*/
  void widthTraversal(TreeNode *head) {
    if (!head)
      return;

    std::vector<int> res;
    std::queue<TreeNode *> que;
    que.push(head);
    while (!que.empty()) {
      TreeNode *cur = que.front();
      que.pop();
      res.push_back(cur->val);
      if (cur->left)
        que.push(cur->left);
      if (cur->right)
        que.push(cur->right);
    }
    while (!que.empty()) {
      res.push_back(que.front()->val);
      que.pop();
    }
  }

  /**
   * @brief 求一个二叉树上最长的水平宽度
   *
   * @param head
   * @return int
   */
  int maxWidth(TreeNode *head) {
    if (head == NULL)
      return 0;

    std::queue<TreeNode *> que;
    std::unordered_map<TreeNode *, int> levelMap;
    int curLevel = 1;
    int curLevelNodes = 0;
    que.push(head);
    levelMap.insert(std::make_pair(head, 1));
    int max = INT_MIN;

    while (!que.empty()) {
      TreeNode *cur = que.front();
      que.pop();
      int currentLevel = levelMap[cur];
      if (currentLevel == curLevel) {
        curLevelNodes++;
      } else {
        max = std::max(max, curLevelNodes);
        curLevel++;
        curLevelNodes = 1;
      }

      if (cur->left != NULL) {
        levelMap.insert({cur->left, currentLevel + 1});
        que.push(cur->left);
      }

      if (cur->right != NULL) {
        levelMap.insert({cur->right, currentLevel + 1});
        que.push(cur->right);
      }
    }
  }

  vector<int> inorderTraversal(TreeNode *root) {
    return inOrderUnRect(root);

    vector<int> res;
    inorderRecur(root, res);
    return res;
  }
};
// @lc code=end
