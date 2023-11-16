/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 *
 * https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (56.42%)
 * Likes:    4109
 * Dislikes: 54
 * Total Accepted:    213.4K
 * Total Submissions: 378.2K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a binary tree, determine if it is a complete binary tree.
 *
 * In a complete binary tree, every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,6]
 * Output: true
 * Explanation: Every level before the last is full (ie. levels with
 * node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are
 * as far left as possible.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,5,null,7]
 * Output: false
 * Explanation: The node with value 7 isn't as far left as possible.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 100].
 * 1 <= Node.val <= 1000
 *
 *
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

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

#include <queue>
class Solution {
public:
  bool isCompleteTree(TreeNode *head) {
    if (!head)
      return true;
    std::queue<TreeNode *> que;
    que.push(head);
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    bool leaf = false;
    while (!que.empty()) {
      head = que.front();
      que.pop();
      left = head->left;
      right = head->right;

    // 1、一个节点有右无左，则这个节点不对
    // 2、如果一个节点遇到了children不全的情况，则后续所有的遍历都应该是叶节点
    //    如果是叶子节点，那么就没有左右children
      if ((!left && right) || (leaf && (left || right)))
        return false;

      if (left)
        que.push(left);
      if (right)
        que.push(right);

// 说明当前节点两个子节点不双全，所以后续判断的时候需要考虑
        if(!left || !right)
        leaf = true;
    }
    return true;
  }
};
// @lc code=end
