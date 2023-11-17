/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (60.74%)
 * Likes:    15506
 * Dislikes: 358
 * Total Accepted:    1.4M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
  /**
   * 情况1: 两个节点互相为最近公公祖先
   *          1
   *         /  \
   *        2   3
   *       / \   \
   *      4  5   6
   *          \
   *          7
   * 判断2、 7 节点的情况，那么最低的就是2
   *
   * 如果判断4、7 ，则最低的就是2
   *
   * // 判断左右两棵树的情况
   * 
   * // 情况1的递归分析：
   * 先从头节点开始，获取2，3节点子树的情况，因为2就是p，所以1的左树返回2
   * 1的右树，3左树是null，右树返回null，所以返回null
   * 故 1 左右获取的结果是 2，null
   * 最终返回2
   * 
   * // 情况2的递归分析：
   * 
   */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL || root == p || root == q)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)
      return root;

    return left ? left : right;
  }
};
// @lc code=end
