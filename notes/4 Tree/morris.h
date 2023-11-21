#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

void morris(TreeNode *node) {
  if (node == NULL)
    return;

  TreeNode *cur = node;
  TreeNode *mostRight = NULL;
  while (cur != NULL) {
    mostRight = cur->left;
    if (mostRight) {
      while (mostRight->right != NULL && mostRight->right != cur) {
        mostRight = mostRight->right;
      }

      if (mostRight->right == NULL) {
        mostRight->right = cur;
        cur = cur->left;
        continue;
      } else {
        mostRight->right = NULL;
      }
    }
    cur = cur->right;
  }
}

void preMorris(TreeNode *node) {
  if (node == NULL)
    return;

  TreeNode *cur = node;
  TreeNode *mostRight = NULL;
  while (cur != NULL) {
    mostRight = cur->left;
    if (mostRight) {
      while (mostRight->right != NULL && mostRight->right != cur) {
        mostRight = mostRight->right;
      }

      if (mostRight->right == NULL) {
        // 先序遍历
        printf("%d ", cur->val);
        mostRight->right = cur;
        cur = cur->left;
        continue;
      } else {
        mostRight->right = NULL;
      }
    } else {
      // 在这里打印就是先序遍历
      printf("%d ", cur->val);
    }
    cur = cur->right;
  }
}

void inOrderMorris(TreeNode *node) {
  if (node == NULL)
    return;

  TreeNode *cur = node;
  TreeNode *mostRight = NULL;
  while (cur != NULL) {
    mostRight = cur->left;
    if (mostRight) {
      while (mostRight->right != NULL && mostRight->right != cur) {
        mostRight = mostRight->right;
      }

      if (mostRight->right == NULL) {
        mostRight->right = cur;
        cur = cur->left;
        continue;
      } else {
        mostRight->right = NULL;
      }
    }
    printf("%d ", cur->val);
    cur = cur->right;
  }
}