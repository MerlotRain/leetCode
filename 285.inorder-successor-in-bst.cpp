#include <stdlib.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
};

class Solution {
public:
  TreeNode *successorInBST(TreeNode *node) {
    if (node == NULL)
      return node;
      // 如果有右树
    if (node->right != NULL) {
      return leftMost(node->right);
    } else {
      TreeNode *parent = node->parent;

      // 是否有爹，而且node不是爹的左孩子
      while (parent != NULL && parent->left != node) {
        node = parent;
        parent = parent->parent;
      }
      return parent;
    }
  }

  TreeNode *leftMost(TreeNode *node) {
    if (!node)
      return NULL;
    while (node->left != NULL) {
      node = node->left;
    }
    return node;
  }
};