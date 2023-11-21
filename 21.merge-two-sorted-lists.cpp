/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (63.39%)
 * Likes:    20506
 * Dislikes: 1915
 * Total Accepted:    3.7M
 * Total Submissions: 5.8M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists into one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: list1 = [], list2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <deque>

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *cur1 = list1;
    ListNode *cur2 = list2;

/**
 * @brief 
 * 1  2  3
 * 1  3  4
 * 
 * 1
 * 1
 */
    ListNode *result = NULL;
    ListNode *node = NULL;
    while (cur1 || cur2) {
      int a = INT_MAX, b = INT_MAX;
      if (cur1) {
        a = cur1->val;
      }
      if (cur2) {
        b = cur2->val;
      }
      int min = std::min(a, b);
      if (node == NULL) {
        result = new ListNode(min);
        node = result;
      } else {
        ListNode *p = new ListNode(min);
        node->next = p;
        node = node->next;
      }
      min == b ? cur2 = cur2->next : cur1 = cur1->next;
    }
    return result;
  }
};
// @lc code=end
